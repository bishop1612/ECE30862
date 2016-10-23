import java.lang.Integer;

class Int implements Comparable {

   Integer i;

   public Int(int j) {i = new Integer(j);}

   // Implement the Comparable interface functions here.
   public double value(){
	   return (double) this.i;
   }
   public boolean lessThan(Comparable c){
	   if (i < c.value())
	   {
		   return true;
	   }
	   return false;
   }
   public boolean equal(Comparable c){
	   if (i == c.value())
	   {
		   return true;
	   }
	   return false;
	   
   }
   public boolean greaterThan(Comparable c){
	   if (i > c.value())
	   {
		   return true;
	   }
	   return false;   
   }


}
