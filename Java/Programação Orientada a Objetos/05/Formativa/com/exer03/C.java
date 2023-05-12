package com.exer03;

import java.util.ArrayList;

public class C {

	public static void main(String[] args) {
		
		ArrayList<Figura> listaDeFiguras = new ArrayList<Figura>();
		
		listaDeFiguras.add(new Quadrado(100F));
		listaDeFiguras.add(new Retangulo(30F, 40F));
		listaDeFiguras.add(new Quadrado(40F));
		listaDeFiguras.add(new Quadrado(20F));
		listaDeFiguras.add(new Retangulo(25F, 40F));
		
		for (Figura figura : listaDeFiguras)
			System.out.println(figura.area());
		
	}

}
