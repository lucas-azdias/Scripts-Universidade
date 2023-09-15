package aula06.wordCount;

import java.io.IOException;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;
import org.apache.log4j.BasicConfigurator;

/* Classe principal (WordCount) do contador de palavras distribuído utilizando Hadoop
Dentro dessa classe, temos:
i) Método principal (main) que realiza as configurações do Hadoop (onde está o arquivo de entrada, qual será o arquivo de saída, registro das classes, etc)
ii) Uma classe MapX que estende a classe Mapper do Hadoop
    ii-b) Um método map que recebe o bloco de dados como entrada e irá percorrer cada linha do arquivo de entrada e gera o par (chave, valor)
iii) Uma classe ReduceX que estende a classe Reducer do Hadoop
    iii-b) Um método reduce que irá receber a saída do map após passar pelo Sort/Shuflle e gera o resultado no formato (chave, valor)
 */
public class WordCountWithCombiner {
    // Método principal da classe
    public static void main(String[] args) throws Exception {
        BasicConfigurator.configure();

        Configuration c = new Configuration();
        String[] files = new GenericOptionsParser(c, args).getRemainingArgs();

        // arquivo de entrada (alterar nas configurações)
        Path input = new Path(files[0]);

        // arquivo de saida (alterar nas configurações)
        Path output = new Path(files[1]);

        // criacao do job e seu nome
        Job j = new Job(c, "wordcount");

        // Registro das classes
        j.setJarByClass(WordCountWithCombiner.class); // main
        j.setMapperClass(MapForWordCount.class); // mapper
        j.setReducerClass(ReduceForWordCount.class); // reducer
        j.setCombinerClass(ReduceForWordCount.class); // COMBINER = REDUCER

        // Definição dos tipos de saída (map e reduce)
        j.setMapOutputKeyClass(Text.class); // chave saída do map
        j.setMapOutputValueClass(IntWritable.class); // valor saída do map
        j.setOutputKeyClass(Text.class); // chave saída do reduce
        j.setOutputValueClass(IntWritable.class); // valor saída do reduce

        // Cadastrar arquivos de entrada e saída
        FileInputFormat.addInputPath(j, input); // entrada
        FileOutputFormat.setOutputPath(j, output); // saída

        // Execução do job
        j.waitForCompletion(true);
    }

    /*
    "Parâmetros" da classe Mapper:
    Tipo 1: tipo da chave de entrada
    Tipo 2: tipo do valor de entrada
    Tipo 3: tipo da chave de saída
    Tipo 4: tipo do valor de saída

    ARQUIVO TEXTO COMO ENTRADA
    - Input: (offset/qtde bytes lidos no arquivo, conteúdo da linha)
     */
    public static class MapForWordCount extends Mapper<LongWritable, Text, Text, IntWritable> {
        /*
        Input: (chave, valor) e contexto
        Os tipos da chave e valor do método map devem ser os mesmos da "entrada" da classe Mapper
        Nesse caso, será LongWritable e Text
         */
        public void map(LongWritable key, Text value, Context con)
                throws IOException, InterruptedException {

            // obtendo conteúdo da linha do arquivo de entrada (value)
            String linha = value.toString().toLowerCase().replaceAll("[^a-z]", " ");

            // quebrando o conteúdo da linha em palavras (vetor de strings)
            String[] palavras = linha.split(" ");

            // gerando (chave, valor) para cada palavra -> (palavra, 1)
            for (String p: palavras){
                if (p.length() > 1){
                    Text chaveSaida = new Text(p); //cast de String -> Text
                    IntWritable valorSaida = new IntWritable(1); //cast de int para IntWritable

                    // enviando pares (chave, valor) para o Sort/Shuffle
                    con.write(chaveSaida, valorSaida);
                }
            }
        }

    }

    /*
    Parâmetros da classe Reducer
    Tipo 1: tipo da chave de entrada (mesmo tipo da chave de saída do map)
    Tipo 2: tipo do valor da entrada (mesmo tipo do valor de saída do map)
    Tipo 3: tipo da chave de saída
    Tipo 4: tipo do valor de saída
     */

    public static class ReduceForWordCount extends Reducer<Text, IntWritable, Text, IntWritable> {
    
    /*
    Input: (chave, valor) e contexto
    Os tipos da chave e valor do método reduce devem ser os mesmos que foram enviados pelo map
    No nosso caso, será Text e Iterable<IntWritable> pois temos a chave (palavra) e uma lista de valores (1, 1, 1, ...) que podemos iterar
     */
        public void reduce(Text key, Iterable<IntWritable> values, Context con)
                throws IOException, InterruptedException {


            // Dada uma chave, somar todas as suas ocorrências
            int soma = 0;
            for (IntWritable v:values) {
                soma+= v.get();
            }


            // cast da variável soma (int) para IntWritable
            IntWritable valorSaida = new IntWritable(soma);

            // salva os resultados no HDFS utilizando o Context
            con.write(key, valorSaida);
            // também poderia ser:
            // con.write(key, new IntWritable(soma));
        }
    }
}
