
public class IntegerArithmetic {
	private static long l1;
	private static long l2;
		
	public IntegerArithmetic(Object l1, Object l2) {
		if (l1 instanceof Long || l1 instanceof Integer){
			IntegerArithmetic.l1 = Long.parseLong(String.valueOf(l1));
			
		}
		else {
			throw new IllegalArgumentException("Arguments must be long or integer");
		}
		
		if (l2 instanceof Long || l2 instanceof Integer){
			IntegerArithmetic.l2 = Long.parseLong(String.valueOf(l2));
			
		}
		else {
			throw new IllegalArgumentException("Arguments must be long or integer");
		}
		// TODO Auto-generated constructor stub
	}
	
	public static long add(){
		return l1 + l2;
	}
	
	
	
	public static long subtract(){
		return l1 - l2;
	}
	
	
	public static long multiply(){
		return l1 * l2;
	}
	
	public static long divide(){
		if (l2 == 0){
			throw new ArithmeticException("Cannot divide a number by 0.");
		}
		return l1 / l2;
	}
	

}
