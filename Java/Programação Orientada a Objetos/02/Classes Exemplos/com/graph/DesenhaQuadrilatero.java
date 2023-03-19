package com.graph;

public class DesenhaQuadrilatero {

    public static void main(String args[]) {
        
        Ponto B = new Ponto(4.5, 7);
        Ponto C = new Ponto(2.8, 9.1);
        Ponto D = new Ponto(7, 9.1);
        Ponto E = new Ponto(7, 7);
        
        Quadrilatero q = new Quadrilatero(B, C, D, E);
        
        q.desenhe();
    }
}
