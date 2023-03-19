package com.carro;


public class Carro {

    public double dar_largada(double a) {
        return 0.0;
    }

    public void mudar_velocidade(double v, double a) {
    }

    public double parar(double a) {
        return 0.0;
    }
    @SuppressWarnings("unused")
	private double velocidade_atual;

    public Carro(double velocidade_inicial) {
        velocidade_atual = velocidade_inicial;
    }
}
