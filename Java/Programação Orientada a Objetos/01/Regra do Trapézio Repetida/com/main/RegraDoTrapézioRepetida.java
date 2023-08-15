package com.main;

import java.util.Scanner;
import java.lang.Math;

public class RegraDoTrap�zioRepetida {

	public static void main(String[] args) {
		
		double a, b;
		int n;
		
		double area_total = 0;
		
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		
		// Leitura de a
		System.out.print("Type the value of a: ");
		a = scanner.nextDouble();
		
		// Leitura de b
		System.out.print("Type the value of b: ");
		b = scanner.nextDouble();
		
		// Verificação para a e b
		if (!(a <= b)) {
			System.out.println("\nERROR. a <= b is not true.");
			System.exit(-1);
		}
		
		// Leitura de n
		System.out.print("Type the quantity of repetitions: ");
		n = scanner.nextInt();
		
		// Verificação para n
		if (!(n > 0)) {
			System.out.println("\nERROR. n > 0 is not true.");
			System.exit(-1);
		}

		// Cálculo da integral
		double x = a;
		double h = (b - a) / n;
		double y1 = f(x);
		for (int i = 0; i < n; i++) {
			x = x + h;
			double y2 = f(x);
			area_total += h * (y1 + y2) / 2;
			y1 = y2;
			
		}
		
		// Imprime resultado
		System.out.println("\nThe total area is equal to " + area_total);

	}
	
	public static double f(double x) {
		return 2 * Math.sin(x) + (Math.cos(x) / 3);
	}

}
