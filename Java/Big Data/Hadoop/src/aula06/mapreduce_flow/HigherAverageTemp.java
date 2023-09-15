package aula06.mapreduce_flow;

import aula06.combiner.FireAvgWithComb;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.FloatWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;
import org.apache.log4j.BasicConfigurator;

import java.io.IOException;
import java.io.Writer;

public class HigherAverageTemp {

    public static void main(String args[]) throws IOException, ClassNotFoundException, InterruptedException {
        BasicConfigurator.configure();

        Configuration c = new Configuration();
        String[] files = new GenericOptionsParser(c, args).getRemainingArgs();
        // arquivo de entrada
        Path input = new Path(files[0]);

        // arquivo intermediario
        Path intermediate = new Path(files[1]);

        // arquivo de saida
        Path output = new Path(files[2]);

        // criacao do job 1 e seu nome
        Job j1 = new Job(c, "media");

        // registro das classes
        j1.setJarByClass(HigherAverageTemp.class);
        j1.setMapperClass(MapForAverage.class);
        j1.setReducerClass(ReduceForAverage.class);
        j1.setCombinerClass(CombineForAverage.class); // exemplo com combiner

        // definição dos tipos de saída (map e reduce)
        j1.setMapOutputKeyClass(Text.class);
        j1.setMapOutputValueClass(FireAvgWithComb.class);
        j1.setOutputKeyClass(Text.class);
        j1.setOutputValueClass(FloatWritable.class);


        // cadastrar os arquivos de entrada e saída
        FileInputFormat.addInputPath(j1, input);
        FileOutputFormat.setOutputPath(j1, intermediate);

        // lanca o job e aguarda sua execucao
        j1.waitForCompletion(true);


        // criacao do job 2 e seu nome
        Job j2 = new Job(c, "maior media");

        // registro das classes
        j2.setJarByClass(HigherAverageTemp.class);
        j2.setMapperClass(MapForHigherAverage.class);
        j2.setReducerClass(ReduceForHigherAverage.class);

        // definição dos tipos de saída (map e reduce)
        j2.setMapOutputKeyClass(Text.class);
        j2.setMapOutputValueClass(HigherFireAvg.class);
        j2.setOutputKeyClass(Text.class);
        j2.setOutputValueClass(FloatWritable.class);


        // cadastrar os arquivos de entrada e saída
        FileInputFormat.addInputPath(j2, intermediate);
        FileOutputFormat.setOutputPath(j2, output);

        // lanca o job e aguarda sua execucao
        j2.waitForCompletion(true);
    }


    public static class MapForAverage extends Mapper<LongWritable, Text, Text, FireAvgWithComb> {

        // Funcao de map
        public void map(LongWritable key, Text value, Context con)
                throws IOException, InterruptedException {

            // obtendo o conteúdo da linha e convertendo para string
            String linha = value.toString();

            // quebrando a linha em colunas
            String[] colunas = linha.split(",");

            // pegando somente a temperatura (index 8)
            float temperatura = Float.parseFloat(colunas[8]);

            // pegando o mês (atividade 2)
            String mes = colunas[2];

            // ocorrência
            int n = 1;

            // passando temperatura e ocorrência para o sort/shuffle com uma chave única "media"
            con.write(new Text("media"), new FireAvgWithComb(temperatura, 1));

            // passando a temperatura por mês (atividade 2)
            con.write(new Text(mes), new FireAvgWithComb(temperatura, 1));
        }
    }

    public static class ReduceForAverage extends Reducer<Text, FireAvgWithComb, Text, FloatWritable> {
        public void reduce(Text key, Iterable<FireAvgWithComb> values, Context con)
                throws IOException, InterruptedException {

            // Chega no reduce, uma chave ÚNICA com uma lista de valores do tipo
            // FireAvgTempWritable (temperatura, ocorrencia)
            float somaTemp=0;
            int somaN=0;
            for(FireAvgWithComb v:values){
                somaTemp+=v.getSomaTemperatura();
                somaN+=v.getOcorrencia();
            }
            // calcula a media
            float media = somaTemp/somaN;

            // escreve o resultado final no HDFS
            con.write(key, new FloatWritable(media));
        }
    }

    // Implementação do combiner (mini-reducer)
    public static class CombineForAverage extends Reducer<Text, FireAvgWithComb, Text, FireAvgWithComb>{
        public void reduce(Text key, Iterable<FireAvgWithComb> values, Context con) throws IOException, InterruptedException {
            // no combiner, vamos somar as temperaturas parciais do bloco e também as ocorrências
            float somaTemp=0;
            int somaN=0;
            for(FireAvgWithComb v:values){
                somaTemp+=v.getSomaTemperatura();
                somaN+=v.getOcorrencia();
            }

            // passando para o reduce, os resultados parciais obtidos em cada mapper
            con.write(key, new FireAvgWithComb(somaTemp, somaN));
        }
    }

    public static  class MapForHigherAverage extends Mapper<LongWritable, Text, Text, HigherFireAvg> {
        public void map(LongWritable key, Text value, Context con) throws IOException, InterruptedException {
            // pega a linha do arquivo intermediario
            String linha = value.toString();

            // separa o conteudo da linha em colunas
            String[] colunas = linha.split("\t");

            String mes = colunas[0];
            float temp = Float.parseFloat(colunas[1]);

            con.write(new Text("maior"), new HigherFireAvg(mes, temp));
        }

    }

    public static class ReduceForHigherAverage extends Reducer<Text, HigherFireAvg, Text, FloatWritable> {
        public void reduce(Text key, Iterable<HigherFireAvg> values, Context con) throws IOException, InterruptedException {
            String maiorMes = "null";
            float maiorTemp = Float.MIN_VALUE;

            for (HigherFireAvg v : values) {
                String mes = v.getMes();
                float temp = v.getTemp();
                if (temp > maiorTemp) {
                    maiorMes = mes;
                    maiorTemp = temp;
                }
            }

            con.write(new Text(maiorMes), new FloatWritable(maiorTemp));
        }

    }

}
