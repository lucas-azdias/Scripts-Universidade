package aula06.highAndLow_rain;

import org.apache.hadoop.io.WritableComparable;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;
import java.util.Objects;

public class DayOfWeekRain implements WritableComparable<DayOfWeekRain> {

    private String dayOfWeek;
    private float rain;

    public DayOfWeekRain() {}

    public DayOfWeekRain(String dayOfWeek, float rain) {
        this.dayOfWeek = dayOfWeek;
        this.rain = rain;
    }

    public String getDayOfWeek() {
        return dayOfWeek;
    }

    public void setDayOfWeek(String dayOfWeek) {
        this.dayOfWeek = dayOfWeek;
    }

    public float getRain() {
        return rain;
    }

    public void setRain(float rain) {
        this.rain = rain;
    }

    @Override
    public String toString() {
        return "DayOfWeekInRain{" +
                "dayOfWeek='" + dayOfWeek + '\'' +
                ", rain='" + rain + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        DayOfWeekRain that = (DayOfWeekRain) o;
        return Objects.equals(dayOfWeek, that.dayOfWeek) && Objects.equals(rain, that.rain);
    }

    @Override
    public int hashCode() {
        return Objects.hash(dayOfWeek, rain);
    }

    @Override
    public int compareTo(DayOfWeekRain o) {
        if (this.hashCode() > o.hashCode()) {
            return 1;
        } else if (this.hashCode() < o.hashCode()) {
            return -1;
        } else {
            return 0;
        }
    }

    @Override
    public void write(DataOutput dataOutput) throws IOException {
        dataOutput.writeUTF(dayOfWeek);
        dataOutput.writeFloat(rain);
    }

    @Override
    public void readFields(DataInput dataInput) throws IOException {
        dayOfWeek = dataInput.readUTF();
        rain = dataInput.readFloat();
    }
}
