package pilha;

public class Stack<T> {
	
	private int top;
	private Object[] array;
	
	Stack(int max_size) {
		this.top = -1;
		this.array = new Object[max_size];
	}
	
	public void put(T element) throws IndexOutOfBoundsException {
		if (top < array.length) {
			top++;
			array[top] = element;
		} else {
			throw new IndexOutOfBoundsException();
		}
	}
	
	@SuppressWarnings("unchecked")
	public T get() throws IndexOutOfBoundsException {
		if (top > -1) {
			T gotten = (T) array[top];
			array[top] = null;
			top--;
			return gotten;
		} else {
			throw new IndexOutOfBoundsException();
		}
	}
	
	public boolean isFull() {
		if (top >= array.length) {
			return true;
		} else {
			return false;
		}
	}
	
	public boolean isEmpty() {
		return !isFull();
	}
	
	public String toString() {
		String str = "";
		for (int i = 0; i < top + 1; i++) {
			str += array[i].toString() + " ";
		}
		return str;
	}

}
