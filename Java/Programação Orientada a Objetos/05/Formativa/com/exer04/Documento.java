package com.exer04;

public class Documento implements Compactavel, Criptografavel {
	
	private String texto;
	
	public Documento(String texto) {
		this.texto = texto;
	}
	
	public void show() {
		System.out.println(texto);
	}

	@Override
	public Documento compactar() {
		return new Documento(texto + "[compactado]");
	}

	@Override
	public Documento criptografar() {
		return new Documento(texto + "[criptografado]");
	}

}
