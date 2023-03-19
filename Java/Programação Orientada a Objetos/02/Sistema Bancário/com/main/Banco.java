package com.main;

public class Banco {

	public static void main(String args[]) {
		// I
		Cliente cliente1 = new Cliente("Jandira Silva", 2500);
		Cliente cliente2 = new Cliente("Sandra Rodrigues", 1800);
		Cliente cliente3 = new Cliente("Luciana Teixeira", 5000);
		
		// II
		cliente1.imprimirDados();
		cliente2.imprimirDados();
		cliente3.imprimirDados();
		
		// III
		cliente1.retirar(1000);
		
		// IV
		cliente1.imprimirDados();
		
		// V
		cliente2.retirar(2000);
		
		// VI
		cliente2.depositar(500);
		
		// VII
		cliente2.imprimirDados();
		
		// VIII
		cliente2.retirar(2000);
		
		// IX
		cliente2.imprimirDados();
		
		// X
		cliente3.depositar(1000);
		
		// XI
		cliente3.imprimirDados();
	}
	
}
