package lista_encadeada;

import javax.management.InvalidAttributeValueException;

public class LinkedList<T> {
	
	private Node<T> first;

	public LinkedList() {
		this.first = null;
	}
	
	public LinkedList(int size) throws InvalidAttributeValueException {
		if (size >= 1) {
			this.first = new Node<T>();
			if (size > 1) {
				Node<T> next, last = first;
				for (int i = 0; i < size; i++) {
					next = new Node<T>();
					last.setNext(next);
				}
			}
		} else {
			throw new InvalidAttributeValueException();
		}
	}
	
	public T get(int index) {
		T data = null;
		if (index < length()) {
			Node<T> next = first;
			for (int i = 0; i < index + 1; i++) {
				if (i == index) {
					data = next.getData();
				} else {
					next = next.getNext();
				}
			}
			return data;
		} else {
			throw new IndexOutOfBoundsException();
		}
	}
	
	public void set() {
		
	}
	
	public void append(T data) {
		Node<T> last = getLastNode();
		if (last != null) {
			last.setNext(new Node<T>(data));
		} else {
			first = new Node<T>(data);
		}
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
	
	private Node<T> getLastNode() {
		Node<T> next = first;
		if (first != null) {
			while (next.getNext() != null) {
				next = next.getNext();
			}
		}
		return next;
	}
	
}
