package aula05.averageTemperature;

import org.apache.hadoop.io.WritableComparable;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;
import java.util.Objects;

/*
Precisamos que essa nova classe seja serializável (Writable) para a transmissão
dos dados entre os DataNodes
No Hadoop, o tipo Writable é sempre um Java Bean.
Java Bean é caracterizado por:
    - ter um construtor padrão (vazio),
    - atributos privados,
    - getters e setters para cada atributo

LEMBRETE: a classe deve ser comparável com ela mesma (etapa sort/shuffle)
 */

public class FireAvgTempWritable implements WritableComparable<FireAvgTempWritable> {
    private float somaTemperatura;
    private int ocorrencia;

    public FireAvgTempWritable() {
    }

    public FireAvgTempWritable(float somaTemperatura, int ocorrencia) {
        this.somaTemperatura = somaTemperatura;
        this.ocorrencia = ocorrencia;
    }

    public float getSomaTemperatura() {
        return somaTemperatura;
    }

    public void setSomaTemperatura(float somaTemperatura) {
        this.somaTemperatura = somaTemperatura;
    }

    public int getOcorrencia() {
        return ocorrencia;
    }

    public void setOcorrencia(int ocorrencia) {
        this.ocorrencia = ocorrencia;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        FireAvgTempWritable that = (FireAvgTempWritable) o;
        return Float.compare(that.somaTemperatura, somaTemperatura) == 0 && ocorrencia == that.ocorrencia;
    }

    @Override
    public int hashCode() {
        return Objects.hash(somaTemperatura, ocorrencia);
    }

    @Override
    public String toString() {
        return super.toString();
    }

    @Override
    public int compareTo(FireAvgTempWritable o) {
        if(this.hashCode() < o.hashCode()){
            return -1;
        }else if(this.hashCode() > o.hashCode()){
            return +1;
        }
        return 0;
    }

    @Override
    public void write(DataOutput dataOutput) throws IOException {
        dataOutput.writeFloat(somaTemperatura);
        dataOutput.writeInt(ocorrencia);
    }

    @Override
    public void readFields(DataInput dataInput) throws IOException {
        somaTemperatura = dataInput.readFloat();
        ocorrencia = dataInput.readInt();
    }
}
