
public class LongList implements MyList{
	LongList next;
	long data;
	
	public LongList(long data) {
		// TODO Auto-generated constructor stub
		this.data = data;
	}
	
	public LongList(LongList n, long data) {
		// TODO Auto-generated constructor stub
		this.data = data;
		this.next = n;
	}
	
	public LongList next( ){
		return this.next;
	}
	@Override
	public void printNode() {
		System.out.print("LongList Node, data is: " + this.data);
		
	}
	public Object clone( ) throws CloneNotSupportedException {
		return super.clone();
	}

}
