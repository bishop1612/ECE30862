
public class IntList implements MyList {
	IntList next;
	int data;
	
	public IntList(int data) {
		this.data = data;
	}

	public IntList(IntList n, int data) {
		this.data = data;
		this.next = n;
	}

	public IntList next( ){
		return this.next;
	}
	@Override
	public void printNode() {
		System.out.print("IntList Node, data is: " + this.data);
		
	}
	public Object clone( ) throws CloneNotSupportedException {
		return super.clone();
	}

}
