package lista_circular;

public class CircularList<T> {
	
	private Node<T> first;

	public CircularList() {
		this.first = null;
	}
	
	public CircularList(int size) {
		if (size >= 1) {
			this.first = new Node<T>();
			if (size > 1) {
				Node<T> next = null, last = first;
				for (int i = 0; i < size; i++) {
					next = new Node<T>();
					last.setNext(next);
					last = next;
				}
				next.setNext(first);
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
			} else {
				afterRemoved = first;
			}
			
			if (index == 0) {
				first = afterRemoved;
				getLastNode().setNext(first);
			} else {
				Node<T> beforeRemoved = getNode(index - 1);
				beforeRemoved.setNext(afterRemoved);
			}
		} else {
			throw new IndexOutOfBoundsException();
		}
	}
	
	public void append(T data) {
		Node<T> next = new Node<T>(data);
		if (first != null) {
			getLastNode().setNext(next);
		} else {
			first = next;
		}
		next.setNext(first);
	}
	
	public void pop() {
		remove(length() - 1);
	}
	
	public int length() {
		int counter = 0;
		Node<T> next = first;
		if (first != null) {
			counter++;
			while (next.getNext() != first) {
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
			} while (next != first);
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
