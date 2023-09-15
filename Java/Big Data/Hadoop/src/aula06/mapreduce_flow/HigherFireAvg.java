package aula06.mapreduce_flow;

import org.apache.hadoop.io.WritableComparable;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;
import java.util.Objects;

public class HigherFireAvg implements WritableComparable<HigherFireAvg> {
    private String mes;
    private float temp;

    public HigherFireAvg() {}

    public HigherFireAvg(String mes, float temp) {
        this.mes = mes;
        this.temp = temp;
    }

    public String getMes() {
        return mes;
    }

    public void setMes(String mes) {
        this.mes = mes;
    }

    public float getTemp() {
        return temp;
    }

    public void setTemp(float temp) {
        this.temp = temp;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        HigherFireAvg that = (HigherFireAvg) o;
        return Float.compare(temp, that.temp) == 0 && Objects.equals(mes, that.mes);
    }

    @Override
    public int hashCode() {
        return Objects.hash(mes, temp);
    }

    @Override
    public String toString() {
        return super.toString();
    }

    @Override
    public int compareTo(HigherFireAvg o) {
        if (this.hashCode() < o.hashCode()) {
            return -1;
        } else if (this.hashCode() > o.hashCode()) {
            return 1;
        } else {
            return 0;
        }
    }

    @Override
    public void write(DataOutput dataOutput) throws IOException {
        dataOutput.writeUTF(mes);
        dataOutput.writeFloat(temp);
    }

    @Override
    public void readFields(DataInput dataInput) throws IOException {
        mes = dataInput.readUTF();
        temp = dataInput.readFloat();
    }
}
