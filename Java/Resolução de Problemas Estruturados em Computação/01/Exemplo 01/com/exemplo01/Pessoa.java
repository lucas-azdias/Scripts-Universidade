package com.exemplo01;

public class Pessoa {
	
	private String nome;
	private String id;
	private String phone;
	
	public Pessoa() {
		this.nome = "";
		this.id = "";
		this.phone = "";
	}
	
	public Pessoa(String nome, String id, String phone) {
		this.nome = nome;
		this.id = id;
		this.phone = phone;
	}
	
	public String show() {
		return nome + " (" + id + ") - CONTATO: " + phone;
	}

}
