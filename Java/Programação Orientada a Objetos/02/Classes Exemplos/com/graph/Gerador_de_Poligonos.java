package com.graph;

public class Gerador_de_Poligonos {

    public Triangulo gere_triangulo(Ponto p1, Ponto p2, Ponto p3) {
        
        Triangulo t = new Triangulo(p1, p2, p3);
        
        return t;
    }

    public Quadrilatero gere_quadrilatero(Ponto p1, Ponto p2, Ponto p3, Ponto p4) {
        
        Quadrilatero q = new Quadrilatero(p1, p2, p3, p4);
        
        return q;

    }
}
