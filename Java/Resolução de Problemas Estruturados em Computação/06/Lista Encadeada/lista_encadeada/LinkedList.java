package lista_encadeada;

public class LinkedList<T> {
	
	private Node<T> first;

	public LinkedList() {
		this.first = null;
	}
	
	public LinkedList(int size) {
		if (size >= 1) {
			this.first = new Node<T>();
			if (size > 1) {
				Node<T> next, last = first;
				for (int i = 0; i < size; i++) {
					next = new Node<T>();
					last.setNext(next);
					last = next;
				}
			}
		} else {
			this.first = null;
		}
	}
	
	public T get(int index) {
		return getNode(index).getData();
	}
	
	public void set(int index, T data) {
		getNode(index).setData(data);
	}
	
	public void remove(int index) {
		if (!isIndexOutOfBounds(index)) {
			Node<T> afterRemoved = null;
			if (index + 1 < length()) {
				afterRemoved = getNode(index + 1);
			}
			
			if (index == 0) {
				first = afterRemoved;
			} else {
				Node<T> beforeRemoved = getNode(index - 1);
				beforeRemoved.setNext(afterRemoved);
			}
		} else {
			throw new IndexOutOfBoundsException();
		}
	}
	
	public void append(T data) {
		if (first != null) {
			getLastNode().setNext(new Node<T>(data));
		} else {
			first = new Node<T>(data);
		}
	}
	
	public void pop() {
		remove(length() - 1);
	}
	
	public int length() {
		int counter = 0;
		Node<T> next = first;
		if (first != null) {
			counter++;
			while (next.getNext() != null) {
				next = next.getNext();
				counter++;
			}
		}
		return counter;
	}
	
	public String toString() {
		String text = "[";
		if (first != null) {
			Node<T> next = first;
			do {
				text += next.getData().toString() + ", ";
				next = next.getNext();
			} while (next != null);
			text = text.substring(0, text.length() - 2);
		}
		text += "]";
		return text;
	}
	
	private Node<T> getLastNode() {
		return getNode(length() - 1);
	}
	
	private Node<T> getNode(int index) {
		if (!isIndexOutOfBounds(index)) {
			Node<T> next = first;
			for (int i = 0; i < index; i++) {
				next = next.getNext();
			}
			return next;
		} else {
			throw new IndexOutOfBoundsException();
		}
	}
	
	private boolean isIndexOutOfBounds(int index) {
		return !(index >= 0 && index < length());
	}
	
}
