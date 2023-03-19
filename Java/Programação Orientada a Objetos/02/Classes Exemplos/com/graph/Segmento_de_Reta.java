package com.graph;

public class Segmento_de_Reta {

    private Ponto p1, p2;

    public Segmento_de_Reta(Ponto p1, Ponto p2) {
        this.p1 = p1;
        this.p2 = p2;
    }

    public void desenhe() {
        System.out.println("Segmento de reta entre "
                + p1.texto() + " e " + p2.texto()); 
        // aqui deve ser usado um pacote gráfico para
        // desenhar o segmento de reta    
    }
}
