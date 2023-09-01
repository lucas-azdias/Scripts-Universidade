package lista_circular;

import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		CircularList<Integer> l = new CircularList<Integer>();
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
