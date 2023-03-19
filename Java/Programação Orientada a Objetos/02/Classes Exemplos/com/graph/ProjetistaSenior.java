package com.graph;

public class ProjetistaSenior {

    public static void main(String args[]) {

        Gerador_de_Poligonos gerador = new Gerador_de_Poligonos();

        Ponto A = new Ponto(2, 3);
        Ponto B = new Ponto(4.5, 7);
        Ponto C = new Ponto(2.8, 9.1);
        Triangulo jardim = gerador.gere_triangulo(A, B, C);

        jardim.desenhe();

        Ponto D = new Ponto(7, 9.1);
        Ponto E = new Ponto(7, 7);
        Quadrilatero sala_estar = gerador.gere_quadrilatero(B, C, D, E);

        sala_estar.desenhe();

        Ponto F = new Ponto(7, 11);
        Ponto G = new Ponto(2.8, 11);
        Quadrilatero sala_jantar = gerador.gere_quadrilatero(C, D, F, G);

        sala_jantar.desenhe();
    }
}
