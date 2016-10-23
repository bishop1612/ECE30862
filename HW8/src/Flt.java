import java.lang.Float;

class Flt implements Comparable {

   Float f; // the value returned by the value method.

   public Flt(float f) {this.f = new Float(f);}
   
// Implement the Comparable interface functions here.
   public double value(){
	   return (double) this.f;
   }
   public boolean lessThan(Comparable c){
	   if (f < c.value())
	   {
		   return true;
	   }
	   return false;
   }
   public boolean equal(Comparable c){
	   if (f == c.value())
	   {
		   return true;
	   }
	   return false;
	   
   }
   public boolean greaterThan(Comparable c){
	   if (f > c.value())
	   {
		   return true;
	   }
	   return false;   
   }

}
