package com.exer01;

public class Gado {
	
	@SuppressWarnings("unused")
	private int codigo;
	private double peso; // em kg
	
	public Gado(int codigo, double peso) {
		this.codigo = codigo;
		this.peso = peso;
	}
	
	public double ganhoDePeso() {
		return peso * 0.2;
	}

}
