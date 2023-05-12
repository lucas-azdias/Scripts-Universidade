package com.exer04;

public class D {

	public static void main(String[] args) {

		Documento arquivo01 = new Documento("FASTA");
		
		Documento arquivo02 = compactado(arquivo01);
		Documento arquivo03 = criptografado(arquivo02);
		
		arquivo01.show();
		arquivo02.show();
		arquivo03.show();

	}
	
	public static Documento compactado(Compactavel arquivo) {
		return arquivo.compactar();
	}
	
	public static Documento criptografado(Criptografavel arquivo) {
		return arquivo.criptografar();
	}

}
