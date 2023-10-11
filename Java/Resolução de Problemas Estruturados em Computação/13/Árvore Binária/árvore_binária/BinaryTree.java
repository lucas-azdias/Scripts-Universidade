package árvore_binária;

public class BinaryTree<T> {
	
	private BinaryTreeNode<T> root;
	
	public BinaryTree() {
		this.setRoot(null);
	}
	
	public BinaryTree(BinaryTreeNode<T> root) {
		this.setRoot(root);
	}

	public BinaryTreeNode<T> getRoot() {
		return root;
	}

	public void setRoot(BinaryTreeNode<T> root) {
		this.root = root;
	}

}
