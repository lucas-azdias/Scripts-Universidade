package pilha;

public class Main {

	public static void main(String[] args) {
		Stack<Integer> p = new Stack<Integer>(5);
		
		p.put(Integer.valueOf(5));
		p.put(Integer.valueOf(9));
		p.put(Integer.valueOf(18));
		
		System.out.println("\"" + p + "\"");
		
		p.get();
		System.out.println("\"" + p + "\"");
		
		p.get();
		System.out.println("\"" + p + "\"");
		
		p.get();
		System.out.println("\"" + p + "\"");
	}
	
}
