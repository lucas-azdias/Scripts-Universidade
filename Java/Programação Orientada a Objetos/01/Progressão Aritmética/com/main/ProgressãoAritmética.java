package com.main;

import java.util.Scanner;

public class ProgressãoAritmética {

	public static void main(String[] args) {
		
		System.out.println("\nARITHMETIC PROGRESSION CALCULATOR\n");
		
		double a1, r;
		int n;
		
		double an, sn;
		
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		
		// Leitura de a1
		System.out.print("Type the value of the first term: ");
		a1 = scanner.nextDouble();
		
		// Leitura de r
		System.out.print("Type the value of the ratio: ");
		r = scanner.nextDouble();
		
		// Leitura de n
		System.out.print("Type the quantity of values: ");
		n = scanner.nextInt();
		
		// Cálculo de an
		an = a1 + (n - 1) * r;
		
		// Cálculo de sn
		sn = n * (a1 + an) / 2;
		
		// Imprime resultado
		System.out.println("\nThe last term is equal to " + an + "\nThe sum of all terms is equal to " + sn);
		
	}

}
