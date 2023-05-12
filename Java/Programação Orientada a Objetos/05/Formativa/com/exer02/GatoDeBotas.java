package com.exer02;

public class GatoDeBotas extends Gato {
	
	private String caracteristica;

	public GatoDeBotas(int numeroDeIdentidade, String pedigree, String caracteristica) {
		super(numeroDeIdentidade, pedigree);
		this.caracteristica = caracteristica;
	}
	
	public String show() {
		return super.show() + ", GatoDeBotas:" + caracteristica;
	}

}
