package com.graph;

public class DesenhaTriangulo {

    public static void main(String args[]) {
        
        Ponto A = new Ponto(2, 3);
        Ponto B = new Ponto(4.5, 7);
        Ponto C = new Ponto(2.8, 9.1);
        
        Triangulo t = new Triangulo(A, B, C);
        
        t.desenhe();
    }
}
