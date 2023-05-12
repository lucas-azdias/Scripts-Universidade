package com.exer02;

public class Gato extends Amigo {
	
	private String pedigree;

	public Gato(int numeroDeIdentidade, String pedigree) {
		super(numeroDeIdentidade);
		this.pedigree = pedigree;
	}
	
	@Override
	public String show() {
		return super.show() + ", Gato:" + pedigree;
	}

}
