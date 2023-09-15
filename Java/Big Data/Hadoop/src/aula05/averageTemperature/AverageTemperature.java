package aula05.averageTemperature;

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

public class AverageTemperature {

    public static void main(String args[]) throws IOException, ClassNotFoundException, InterruptedException {
        BasicConfigurator.configure();

        Configuration c = new Configuration();
        String[] files = new GenericOptionsParser(c, args).getRemainingArgs();
        // arquivo de entrada
        Path input = new Path(files[0]);

        // arquivo de saida
        Path output = new Path(files[1]);

        // criacao do job e seu nome
        Job j = new Job(c, "media");

        // registro das classes
        j.setJarByClass(AverageTemperature.class);
        j.setMapperClass(MapForAverage.class);
        j.setReducerClass(ReduceForAverage.class);

        // definição dos tipos de saída (map e reduce)
        j.setMapOutputKeyClass(Text.class);
        j.setMapOutputValueClass(FireAvgTempWritable.class);
        j.setOutputKeyClass(Text.class);
        j.setOutputValueClass(FloatWritable.class);


        // cadastrar os arquivos de entrada e saída
        FileInputFormat.addInputPath(j, input);
        FileOutputFormat.setOutputPath(j, output);

        // lanca o job e aguarda sua execucao
        System.exit(j.waitForCompletion(true) ? 0 : 1);
    }


    public static class MapForAverage extends Mapper<LongWritable, Text, Text, FireAvgTempWritable> {

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
            con.write(new Text("media"), new FireAvgTempWritable(temperatura, 1));

            // passando a temperatura por mês (atividade 2)
            con.write(new Text(mes), new FireAvgTempWritable(temperatura, 1));
        }
    }

    public static class ReduceForAverage extends Reducer<Text, FireAvgTempWritable, Text, FloatWritable> {
        public void reduce(Text key, Iterable<FireAvgTempWritable> values, Context con)
                throws IOException, InterruptedException {

            // Chega no reduce, uma chave ÚNICA com uma lista de valores do tipo
            // FireAvgTempWritable (temperatura, ocorrencia)
            float somaTemp=0;
            int somaN=0;
            for(FireAvgTempWritable v:values){
                somaTemp+=v.getSomaTemperatura();
                somaN+=v.getOcorrencia();
            }
            // calcula a media
            float media = somaTemp/somaN;

            // escreve o resultado final no HDFS
            con.write(key, new FloatWritable(media));
        }
    }

}
