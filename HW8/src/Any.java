// A simple demonstration of the existence of the Object class 
// and the hashCode method defined by the Object class.
class Any implements Comparable{

   final double value;

   public Any( ) {
      value = hashCode( );
   }
   
   public double value(){
	   return (double) this.value;
   }
   public boolean lessThan(Comparable c){
	   if (value < c.value())
	   {
		   return true;
	   }
	   return false;
   }
   public boolean equal(Comparable c){
	   if (value == c.value())
	   {
		   return true;
	   }
	   return false;
	   
   }
   public boolean greaterThan(Comparable c){
	   if (value > c.value())
	   {
		   return true;
	   }
	   return false;   
   }
   
   

}
