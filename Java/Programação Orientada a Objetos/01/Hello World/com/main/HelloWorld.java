package com.main;

import java.util.Scanner;

public class HelloWorld {

	public static void main(String[] args) {
		
		// Saída de dados
		System.out.println("Hello World!");

		/* Tipos primitivos
		 * 
		 * TIPO       BYTES
		 * byte       1
		 * short      2
		 * int        4
		 * long       8
		 * float      4
		 * double     8
		 * boolean    1
		 * char       2
		 * */
		
		// Entrada de dados
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		System.out.print("Type a number: ");
		int num = scanner.nextInt();
		System.out.println("The number typed is: " + num);
		
		// Operadores lógicos
		// AND - && | OR - ||
		// Obs.: Para aumentar eficiência do código, em operadores &&, faça a condição mais provável de dar False no começo, pois caso a primeira condição for falsa, então a próxima não será testada
	}
 
}
