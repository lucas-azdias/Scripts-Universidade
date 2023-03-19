package com.main;

public class Cliente {
	
	private String nome;
	private double saldoConta;
	
	public Cliente(String nome, double saldoConta) {
		this.nome = nome;
		this.saldoConta = saldoConta;
	}
	
	public void depositar(double valor) {
		saldoConta += valor;
	}
	
	public boolean retirar(double valor) {
		if (saldoConta > valor) {
			saldoConta -= valor;
			return true;
		} else {
			return false;
		}
	}
	
	public void imprimirDados() {
		System.out.println("Nome: " + nome);
		System.out.println("Saldo em conta: " + saldoConta);
	}

}
