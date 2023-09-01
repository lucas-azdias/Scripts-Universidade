package lista_encadeada;

public class Main {
	
	public static void main(String[] args) {
		LinkedList<Integer> l = new LinkedList<Integer>();

		for (int i = 0; i < 100; i++) {
			System.out.println("Teste " + (i + 1));
			
			l.append(Integer.valueOf((i * 3) + 1));
			l.append(Integer.valueOf((i * 3) + 2));
			l.append(Integer.valueOf((i * 3) + 3));
			
			System.out.println(
					l.get((i * 3) + 1 - 1) + " " +
					l.get((i * 3) + 2 - 1) + " " +
					l.get((i * 3) + 3 - 1) + " " +
					"LENGTH: " + l.length()
			);
		}
	}

}
