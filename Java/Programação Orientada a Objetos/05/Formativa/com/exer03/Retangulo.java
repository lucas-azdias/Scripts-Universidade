package com.exer03;

public class Retangulo extends Figura {
	
	private float b, h;
	
	public Retangulo(float b, float h) {
		this.b = b;
		this.h = h;
	}

	@Override
	public float area() {
		return b * h;
	}

}
