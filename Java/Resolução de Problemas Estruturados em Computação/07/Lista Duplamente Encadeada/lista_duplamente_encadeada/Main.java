package lista_duplamente_encadeada;

import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		DoubleLinkedList<Integer> l = new DoubleLinkedList<Integer>();
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("NUMBER TYPER\n(\"-1\" for exit)\n");

		int input;
		do {
			System.out.print("Type a number: ");
			input = scanner.nextInt();
			l.append(input);
		} while (input != -1);
		l.pop();
		
		System.out.println(l);
		
		System.out.println("\nProgram ended.");
	}

}
