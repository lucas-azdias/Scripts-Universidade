package exercício01;

public class Media {
	
	public static void main(String[] args) {
		int[] a = { 9, 1, 3, 3, 5, 6, 3, 2, 2, 1, 1, 3 };
		System.out.println(calcMedia(a));
	}
	
	public static float calcMedia(int[] a) {
		float sum = 0;
		for (int val : a) {
			sum += val;
		}
		return sum / a.length;
	}
}
