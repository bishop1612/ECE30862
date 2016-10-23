
public interface MyList extends Cloneable {
	
	public MyList next();
	
	public void printNode();
	
	public Object clone() throws CloneNotSupportedException;

}
