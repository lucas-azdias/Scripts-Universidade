package com.exer02;

import java.io.Serializable;

public class Pessoa implements Serializable {
	
	private static final long serialVersionUID = 1L;
	
	private String nome;
	private int idade;
	
	public Pessoa(String nome, int idade) {
		this.nome = nome;
		this.idade  = idade;
	}
	
	public String toString() {
		return "Pessoa: " + nome + ", " + idade;
	}

}
