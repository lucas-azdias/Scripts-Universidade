package árvore_binária_busca;

public class SearchBinaryTreeNode {
	
	private Integer data;
	private SearchBinaryTreeNode left;
	private SearchBinaryTreeNode right;
	
	public SearchBinaryTreeNode() {
		this.data = null;
		this.left = null;
	}
	
	public SearchBinaryTreeNode(int data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}
	
	public SearchBinaryTreeNode(int data, SearchBinaryTreeNode left, SearchBinaryTreeNode right) {
		this.data = data;
		this.left = left;
		this.right = right;
	}

	public Integer getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public SearchBinaryTreeNode getLeft() {
		return left;
	}

	public void setLeft(SearchBinaryTreeNode left) {
		this.left = left;
	}
	
	public SearchBinaryTreeNode getRight() {
		return right;
	}

	public void setRight(SearchBinaryTreeNode right) {
		this.right = right;
	}

	public void insert(int value) {
		if (data == null) {
			data = value;
		} else if (data.intValue() <= value) {
			if (right == null) {
				right = new SearchBinaryTreeNode();
			}
			right.insert(value);
		} else {
			if (left == null) {
				left = new SearchBinaryTreeNode();
			}
			left.insert(value);
		}
	}
	
	public String getPreorder() {
		String text = "";
		if (data != null) {
			text += data.toString() + "|";
		}
		if (left != null) {
			text += left.getPreorder();
		}
		if (right != null) {
			text += right.getPreorder();
		}
		return text;
	}
	
	public String getInorder() {
		String text = "";
		if (left != null) {
			text += left.getInorder();
		}
		if (data != null) {
			text += data.toString() + "|";
		}
		if (right != null) {
			text += right.getInorder();
		}
		return text;
	}
	
	public String getPostorder() {
		String text = "";
		if (left != null) {
			text += left.getPostorder();
		}
		if (right != null) {
			text += right.getPostorder();
		}
		if (data != null) {
			text += data.toString() + "|";
		}
		return text;
	}
	
	public void popMin() {
		if (left != null && left.getLeft() == null) {
			setLeft(null);
		} else {
			left.popMin();
		}
	}
	
	public void popMax() {
		if (right != null && right.getRight() == null) {
			setRight(null);
		} else {
			right.popMax();
		}
	}
	
	public void remove(int value) {
		removeNode(this, value);
	}
	
	public String toString() {
		String text = "";
		if (data != null) {
			text += data.toString();
		}
		if (left != null) {
			text += "{" + left.toString() + "}";
		} else if (right != null) {
			text += "{" + "}";
		}
		if (right != null) {
			text += "{" + right.toString() + "}";
		} else if (left != null) {
			text += "{" + "}";
		}
		return text;
	}
	
	private static SearchBinaryTreeNode removeNode(SearchBinaryTreeNode node, int value) {
		if (node == null) {
			return null;
		}
		
		if (node.getData().intValue() > value) {
			node.setLeft(removeNode(node.getLeft(), value));
		} else if (node.getData().intValue() < value) {
			node.setRight(removeNode(node.getRight(), value));
		} else { // this node must be deleted
			
			// has one child cases
			if (node.getLeft() == null) {
				return node.getRight();
			} else if (node.getRight() == null) {
				return node.getLeft();
			}
			
			// balances the subtree
			node.setData(getMinValue(node.getRight()));
			node.setRight(removeNode(node.getRight(), node.getData()));
		}
		
		return node;
	}
	
	private static int getMinValue(SearchBinaryTreeNode node) {
		int minValue = node.getData();
        while (node.getLeft() != null) {
            minValue = node.getLeft().getData();
            node = node.getLeft();
        }
        return minValue;
	}
	
}
