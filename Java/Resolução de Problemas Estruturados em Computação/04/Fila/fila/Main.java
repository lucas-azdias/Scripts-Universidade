package fila;

public class Main {

	public static void main(String[] args) {
		Queue<Integer> p = new Queue<Integer>(3);

		for (int i = 0; i < 100; i++) {
			System.out.println("Teste " + (i + 1));
			
			System.out.println(p.isFull());
			System.out.println(p.isEmpty());
			
			p.put(Integer.valueOf(5));
			p.put(Integer.valueOf(9));
			p.put(Integer.valueOf(18));
			
			System.out.println(p.isFull());
			System.out.println(p.isEmpty());
			
			System.out.println("\"" + p + "\"");
			
			p.get();
			System.out.println("\"" + p + "\"");
			
			p.get();
			System.out.println("\"" + p + "\"");
			
			p.get();
			System.out.println("\"" + p + "\"");
		}
	}
}
