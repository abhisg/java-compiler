/*---inheritance
-----polymorphism(method overriding)
-----explicit constructor invocation
-----default and parameterised constructors
----static and non static members
----this and super keywords*/
class sup
{
	static int var;
	int x,y,z;

	public sup()			/*overloaded constructors*/
	{
		x=-1;
		y=-2;
		z=-3;
	}

	public sup(int x)
	{
		this.x=x;
		y=2;
		z=3;
	}

	public void printer1()
	{
		System.out.println("foo1");
	}
	public void printer2()
	{
		System.out.println("foo2");
	}
}
class chi extends sup
{
	public chi()
	{
		super(sup.var);			/*super keyword*/
	}
	public void printer1()			/*polymorphism*/
	{
		System.out.print("calling printer1 of parent:");
		super.printer1();
		System.out.print("printing printer1 from child class:");
		System.out.println("bar");
	}
}
public class inherit
{
	public static void main(String args[])
	{
		sup o1=new sup();
		sup.var=1024;				/*static member access*/
		chi o2=new chi();
		System.out.print("Sum of default arguments:");
		System.out.println(o1.x+o1.y+o1.z);	
		System.out.print("Sum of non static arguments:");
		System.out.println(o2.x+o2.y+o2.z);		/*inheritance of member variables*/
		System.out.print("call from object of super class to printer1:");
		o1.printer1();
		System.out.print("call from object of child class to printer1:");
		o2.printer1();
		System.out.print("call from object of child class to printer2:");
		o2.printer2();
	}
}
