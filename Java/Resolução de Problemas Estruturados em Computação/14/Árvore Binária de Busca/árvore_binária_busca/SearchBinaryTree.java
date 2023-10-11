package árvore_binária_busca;

public class SearchBinaryTree {
	
	private SearchBinaryTreeNode root;
	
	public SearchBinaryTree() {
		this.setRoot(null);
	}
	
	public SearchBinaryTree(SearchBinaryTreeNode root) {
		this.setRoot(root);
	}

	public void setRoot(SearchBinaryTreeNode root) {
		this.root = root;
	}
	
	public void insert(int value) {
		if (root == null) {
			root = new SearchBinaryTreeNode(value);
		} else {
			root.insert(value);
		}
	}
	
	public String getPreorder() {
		return root.getPreorder();
	}
	
	public String getInorder() {
		return root.getInorder();
	}
	
	public String getPostorder() {
		return root.getPostorder();
	}
	
	public void popMin() {
		root.popMin();
	}
	
	public void popMax() {
		root.popMax();
	}
	
	public void remove(int value) {
		root.remove(value);
	}
	
	public String toString() {
		return root.toString();
	}

}
