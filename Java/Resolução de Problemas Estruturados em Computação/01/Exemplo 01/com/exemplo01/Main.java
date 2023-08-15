package com.exemplo01;

import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		int size = 5;
		Pessoa[] pessoas = new Pessoa[size];
		
		Scanner scanner = new Scanner(System.in);
		
		for (int i = 0; i < size; i++) {
			System.out.println("Cadastrando Pessoa " + (i + 1) + "...");
			
			System.out.print("Digite o nome: ");
			String name = scanner.nextLine();
			
			System.out.print("Digite o CPF: ");
			String id = scanner.next();
			
			System.out.print("Digite o telefone: ");
			String phone = scanner.next();
			
			System.out.println();
			
			pessoas[i] = new Pessoa(name, id, phone);
		}
		scanner.close();
		
		System.out.println("Mostrando pessoas cadastradas...");
		for (Pessoa pessoa : pessoas) {
			System.out.println(pessoa.show());
		}
	}

}
