package com.exer02;

import java.io.Serializable;
import java.util.ArrayList;

public class Empresa implements Serializable {
	
	private static final long serialVersionUID = 1L;
	
	private String razaoSocial;
	private ArrayList<Pessoa> funcionarios;
	
	public Empresa(String razaoSocial) {
		this.razaoSocial = razaoSocial;
		this.funcionarios = new ArrayList<Pessoa>();
	}
	
	public void addFuncionario(Pessoa pessoa) {
		funcionarios.add(pessoa);
	}
	
	public void printFuncionarios() {
	}
	
	public String toString() {
		String textFunc = "";
		for (Pessoa pessoa : funcionarios) {
			textFunc += pessoa.toString() + "\n";
		}
		return "Empresa: " + razaoSocial + "\n[\n" + textFunc + "]";
	}

}
