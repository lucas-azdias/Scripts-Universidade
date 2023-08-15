package exercício02;

public class Moda {
	
	public static void main(String[] args) {
		int[] a = { 9, 1, 3, 3, 5, 6, 3, 2, 2, 1, 1, 3 };
		System.out.println(calcModa(a));
	}
	
	public static int calcModa(int[] a) {
		int moda = 0;
		int repModa = 0;
		for (int j = 0; j < a.length; j++) {
			int test = a[j];
			int repTest = 0;
			for (int i = 0; i < a.length; i++) {
				if (a[i] == test) {
					repTest++;
				}
			}
			if (repTest > repModa) {
				moda = test;
			}
		}
		// Se repModa for 0 ou 1, então não há moda
		return moda;
	}

}
