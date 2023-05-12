package com.exer02;

public class Amigo {
	
	private int numeroDeIdentidade;
	
	public Amigo(int numeroDeIdentidade) {
		this.numeroDeIdentidade = numeroDeIdentidade;
	}
	
	public String show() {
		return "Amigo:" + numeroDeIdentidade;
	}

}
