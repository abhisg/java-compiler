/**
keywords used:
public
    class
    double
    int
    char
    boolean
    long
    static
    byte
    this
    void
    new
    for
operators used:
Arithmetic:-,++
Relational:<
Bitwise:
Logical:
Assignment:=
Conditional:



public class finaltest
{
	char var3;
	static byte var;
	char[] var6;

	public finaltest()		/*default constrctor*/
	{
		this.var6 = new char[20];
		var3='a';
		System.out.println("created using default constructor");
		System.out.println(var3);
	}

	public finaltest(char custom)	/*constructor overloading*/   /*parameterised constructor*/
	{
		this();			/*explicit constructor invocation*/
		System.out.println("created using parameterised constructor");
		var3=custom;
	}
	
}

public class ma
{
	static void init(char arr[])			/*passing array as a parameter*/
	{
		byte i;
		finaltest ob=new finaltest();		/*new operator for object creation,default constructor*/
		char v=ob.var3;				/*field access*/
		for(i=0;i<finaltest.var;)		/*update ommited*/
		{
			arr[i]=v;
			v++;
			++i;
		}
		for(i=0;;)				/*condition and update omitted*/
		{
			if(i>=finaltest.var)		/*break statement*/
				break;
			System.out.print(arr[i]);
			System.out.print(" ");
			i++;
		}
		System.out.println();
		
		finaltest ob2=new finaltest('e');	/*new operator for object creation*/
		v=ob2.var3;			/*field access*/
		for(i=0;i<finaltest.var;)		/*update ommited*/
		{
			arr[i]=v;
			v++;
			++i;
		}
		i=0;
		for(;;)				/*initialisation,condition and update omitted*/
		{
			if(i>=finaltest.var)		/*break statement*/
				break;
			System.out.print(arr[i]);
			System.out.print(" ");
			i++;
		}
		System.out.println();
	}
	
	public static void main(String args[])
	{
		finaltest.var=12;
		char arr[]=new char[finaltest.var];
		init(arr);

		finaltest[] ob= new finaltest[20];
		int k,j;
			for(k=0;k<20;k++){
				ob[k]=new finaltest();
				char v='a';
				for(j=0;j<20;j++)
				{
					ob[k].var6[j]=v++;		
					System.out.print(ob[k].var6[j]);
					System.out.print(" ");
				}
				System.out.println();
			}
	}
}
