package com.exer01;

public class Bovino extends Gado {
	
	private float altura;

	public Bovino(int codigo, double peso, float altura) {
		super(codigo, peso);
		this.altura = altura;
	}
	
	@Override
	public double ganhoDePeso() {
		return super.ganhoDePeso() + (altura * 0.2);
	}

}
