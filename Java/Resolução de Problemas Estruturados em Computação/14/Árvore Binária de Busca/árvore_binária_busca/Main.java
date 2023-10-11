package árvore_binária_busca;

public class Main {

	public static void main(String[] args) {
		SearchBinaryTree t = new SearchBinaryTree();
		// 1 - Escreva um algoritmo para inserir um elemento em uma
		// árvore binária de busca.
		t.insert(14);
		t.insert(4);
		t.insert(3);
		t.insert(9);
		t.insert(9);
		t.insert(7);
		t.insert(5);
		t.insert(5);
		t.insert(4);
		t.insert(15);
		t.insert(14);
		t.insert(18);
		t.insert(20);
		t.insert(16);
		t.insert(17);
		System.out.println(t.toString());
		
		// 2 - Escreva algoritmos para percorrer uma árvore binária
		// nas formas préordem, inordem e pósordem.
		System.out.println(t.getPreorder());
		System.out.println(t.getInorder());
		System.out.println(t.getPostorder());
		
		// 3 - Escreva um algoritmo para remover o maior elemento de
		// uma árvore binária de busca.
		t.popMax();
		System.out.println(t.toString());
		
		// 4 - Escreva um algoritmo para remover o menor elemento de
		// uma árvore binária de busca.
		t.popMin();
		System.out.println(t.toString());
		
		// 5 - Considere que uma árvore binária de busca não possui
		// elementos repetidos. Escreva um algoritmo que remova um
		// determinado elemento com valor N da árvore.
		t.remove(18);
		System.out.println(t.toString());
	}

}
