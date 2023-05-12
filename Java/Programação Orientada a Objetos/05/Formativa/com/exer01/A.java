package com.exer01;

public class A {

	public static void main(String[] args) {
			
		Bovino g = new Bovino(101, 300, 1.5F);
		Equino n = new Equino(102, 200, 2.0F);
		
		System.out.println(g.ganhoDePeso());
		System.out.println(n.ganhoDePeso());
		
	}

}
