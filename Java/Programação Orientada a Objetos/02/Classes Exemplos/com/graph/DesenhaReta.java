package com.graph;

public class DesenhaReta {

    public static void main(String args[]) {
        
        Ponto A = new Ponto(2, 3);
        Ponto B = new Ponto(4.5, 7);
        
        Segmento_de_Reta r = new Segmento_de_Reta(A, B);
        
        r.desenhe();
    }
}
