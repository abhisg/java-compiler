/**keywords used:
public
    interface
    void
    class
    implements
    extends
    static
    double
    int
    return
    new
operators used:
Arithmetic:
Relational:
Bitwise:
Logical:
Assignment:=
Conditional:*/





public interface Animal {		/*interface declaration*/

   public void eat();
   public void travel();
}
class MammalInt implements Animal{		/*interface implementation*/

   public void eat(){
      System.out.println("Mammal eats");
   }

   public void travel(){
      System.out.println("Mammal travels");
   } 


}

class Dog extends MammalInt implements Animal{	/*inheritance and interface implementation*/
   
 public void eat(){					/*polymorphism*/
	System.out.println("Dog eats");
 }

	
   public void barks()
	{
		System.out.println("Dog barks");
	}
	
   public static void main(String args[]){
       	MammalInt m,n;
	m =new Dog();
	n=new MammalInt();
	m.eat();
      	m.travel();
	m.barks();
       	System.out.println();
	n.eat();
      	n.travel();
	
   }
}
