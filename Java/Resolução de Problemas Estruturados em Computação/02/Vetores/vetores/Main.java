package vetores;

public class Main {
	
	// ARRAY (Vetor)
	// é ordenado, tem tamanho definido e engloba apenas um tipo/classe

	public static void main(String[] args) {
		// Vetor
		int[] a = new int[6];
		a[0] = 10;
		a[1] = 25;
		a[2] = 5;
		a[3] = 3;
		a[4] = 50;
		a[5] = 14;
		
		// Ordenando...
		int temp;
		for (int j = 0; j < a.length / 2; j++) {
			for (int i = 0; i < a.length - 1; i++) {
				printIntArray(a);
				if (a[i] > a[i + 1]) {
					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
				}
			}
		}
		printIntArray(a);
	}
	
	public static void printIntArray(int[] intArray) {
		for (int i : intArray) {
			System.out.print(i + " ");
		}
		System.out.println();
	}

}
