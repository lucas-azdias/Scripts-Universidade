package aula06.highAndLow_rain;

import aula06.combiner.FireAvgWithComb;
import aula06.mapreduce_flow.HigherFireAvg;
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
import java.time.DayOfWeek;

public class HighAndLowRain {

    public static void main(String args[]) throws IOException, ClassNotFoundException, InterruptedException {
        BasicConfigurator.configure();

        Configuration c = new Configuration();
        String[] files = new GenericOptionsParser(c, args).getRemainingArgs();

        Path input = new Path(files[0]);
        Path intermediate = new Path(files[1]);
        Path output = new Path(files[2]);

        // Job 1
        Job j1 = new Job(c, "day_of_week_rain");

        j1.setJarByClass(HighAndLowRain.class);
        j1.setMapperClass(MapForDayOfWeekRain.class);
        j1.setReducerClass(ReduceForDayOfWeekRain.class);

        j1.setMapOutputKeyClass(Text.class);
        j1.setMapOutputValueClass(FloatWritable.class);
        j1.setOutputKeyClass(Text.class);
        j1.setOutputValueClass(FloatWritable.class);

        FileInputFormat.addInputPath(j1, input);
        FileOutputFormat.setOutputPath(j1, intermediate);

        j1.waitForCompletion(true);

        // Job 2
        Job j2 = new Job(c, "high_and_low_rain");

        j2.setJarByClass(HighAndLowRain.class);
        j2.setMapperClass(MapForHighAndLowRain.class);
        j2.setReducerClass(ReduceForHighAndLowRain.class);

        j2.setMapOutputKeyClass(Text.class);
        j2.setMapOutputValueClass(DayOfWeekRain.class);
        j2.setOutputKeyClass(Text.class);
        j2.setOutputValueClass(FloatWritable.class);

        FileInputFormat.addInputPath(j2, intermediate);
        FileOutputFormat.setOutputPath(j2, output);

        j2.waitForCompletion(true);
    }

    public static class MapForDayOfWeekRain extends Mapper<LongWritable, Text, Text, FloatWritable> {

        public void map(LongWritable key, Text value, Context con) throws IOException, InterruptedException {
            String[] columns = value.toString().split(",");

            String dayOfWeek = columns[3];
            float rain = Float.parseFloat(columns[11]);

            con.write(new Text(dayOfWeek), new FloatWritable(rain));
        }

    }

    public static class ReduceForDayOfWeekRain extends Reducer<Text, FloatWritable, Text, FloatWritable> {

        public void reduce(Text key, Iterable<FloatWritable> values, Context con) throws IOException, InterruptedException {
            float totalRain = 0;
            for (FloatWritable v : values) {
                totalRain += v.get();
            }

            con.write(key, new FloatWritable(totalRain));
        }

    }

    public static class MapForHighAndLowRain extends Mapper<LongWritable, Text, Text, DayOfWeekRain> {

        public void map(LongWritable key, Text value, Context con) throws IOException, InterruptedException {
            String[] columns = value.toString().split("\t");

            String dayOfWeek = columns[0];
            float rain = Float.parseFloat(columns[1]);

            con.write(new Text("highAndLow"), new DayOfWeekRain(dayOfWeek, rain));
        }

    }

    public static class ReduceForHighAndLowRain extends Reducer<Text, DayOfWeekRain, Text, FloatWritable> {

        public void reduce(Text key, Iterable<DayOfWeekRain> values, Context con) throws IOException, InterruptedException {
            DayOfWeekRain lowestRain = new DayOfWeekRain("", Float.MAX_VALUE);
            DayOfWeekRain highestRain = new DayOfWeekRain("", Float.MIN_VALUE);
            for (DayOfWeekRain v : values) {
                if (lowestRain.getRain() > v.getRain()) {
                    lowestRain = v;
                }
                if (highestRain.getRain() < v.getRain()) {
                    highestRain = v;
                }
            }

            con.write(new Text(lowestRain.getDayOfWeek()), new FloatWritable(lowestRain.getRain()));
            con.write(new Text(highestRain.getDayOfWeek()), new FloatWritable(highestRain.getRain()));
        }

    }

}
