package com.graph;

public class Quadrilatero {

    private Ponto p1, p2, p3, p4;

    public Quadrilatero(Ponto p1, Ponto p2, Ponto p3, Ponto p4) {
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
        this.p4 = p4;
    }

    public void desenhe() {
        
        Segmento_de_Reta r1 = new Segmento_de_Reta(p1, p2);
        Segmento_de_Reta r2 = new Segmento_de_Reta(p2, p3);
        Segmento_de_Reta r3 = new Segmento_de_Reta(p3, p4);
        Segmento_de_Reta r4 = new Segmento_de_Reta(p4, p1);
        
        r1.desenhe();
        r2.desenhe();
        r3.desenhe();
        r4.desenhe();

    }
}
