package com.carro;

public class Piloto {

    @SuppressWarnings("unused")
	public static void main(String args[]) {

        Carro c = new Carro(20);

		double t1 = c.dar_largada(0.2);
        c.mudar_velocidade(100, 0.1);
        double t2 = c.parar(0.7);
    }
}
