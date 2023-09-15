package busca_binaria;

public class Main {
	
	public static int binarySearchRecursive(int[] data, int x, int start, int stop) {
		if (start > stop) {
			return -1;
		}
		
		int mid = (start + stop) / 2;
		if (x == data[mid]) {
			return mid;
		} else if (x > data[mid]) {
			return binarySearchRecursive(data, x, mid + 1, stop);
		} else {
			return binarySearchRecursive(data, x, start, mid - 1);
		}
	}
	
	public static int binarySearchIterative(int[] data, int x, int start, int stop) {
		if (start > stop) {
			return -1;
		}
		
		int mid;
		do {
			mid = (start + stop) / 2;
			if (x == data[mid]) {
				return mid;
			} else if (x > data[mid]) {
				start = mid + 1;
			} else {
				stop = mid - 1;
			}
		} while (x != data[mid]);
		
		return mid;
	}
	
	public static void main(String[] args) {
		int[] data = { 1, 2, 3, 4, 5, 6, 7, 8 };
		System.out.println(binarySearchRecursive(data, 8, 0, 7));
		System.out.println(binarySearchIterative(data, 8, 0, 7));
	}

}
