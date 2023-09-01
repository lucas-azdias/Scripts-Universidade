package pilha;

public class Stack<T> {
	
	private int top;
	private Object[] array;
	
	Stack(int max_size) {
		this.top = -1;
		this.array = new Object[max_size];
	}
	
	public void put(T element) throws IndexOutOfBoundsException {
		if (!isFull()) {
			top++;
			array[top] = element;
		} else {
			throw new IndexOutOfBoundsException();
		}
	}
	
	@SuppressWarnings("unchecked")
	public T get() throws IndexOutOfBoundsException {
		if (!isEmpty()) {
			T gotten = (T) array[top];
			array[top] = null;
			top--;
			return gotten;
		} else {
			throw new IndexOutOfBoundsException();
		}
	}
	
	public boolean isFull() {
		return top >= array.length - 1;
	}
	
	public boolean isEmpty() {
		return top <= -1;
	}
	
	public int length() {
		return array.length;
	}
	
	public String toString() {
		String str = "";
		for (int i = 0; i < top + 1; i++) {
			str += array[i].toString() + " ";
		}
		return str;
	}

}
