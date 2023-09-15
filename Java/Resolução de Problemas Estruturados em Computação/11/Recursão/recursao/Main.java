package recursao;

public class Main {
	
	public static void iterativo(int n) {
		if (n < 10) {
			System.out.println(n);
			iterativo(n + 1);
		}
	}
	
	public static int expo_ite(int base, int expo) {
		if (expo == 0) {
			return 1;
		} else {
			return base * expo_ite(base, expo - 1);
		}
	}

	public static void main(String[] args) {
		iterativo(-1);
		System.out.println("\n");
		System.out.println(expo_ite(2, 8));
	}

}
