package com.exer01;

public class Equino extends Gado {
	
	private float idade;

	public Equino(int codigo, double peso, float idade) {
		super(codigo, peso);
		this.idade = idade;
	}
	
	@Override
	public double ganhoDePeso() {
		return idade * 20;
	}
	
}
