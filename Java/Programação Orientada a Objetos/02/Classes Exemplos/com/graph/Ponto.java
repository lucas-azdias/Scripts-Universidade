package com.graph;

public class Ponto {
    
    private double x;
    private double y;

    public Ponto(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public String texto() {
        String t = "(" + x + ", " + y + ")";
        return t;
    }   
}
