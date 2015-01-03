/**----overloaded constructors(parameter=double values)
  ----explicit constructor invocation(this)
  ----passing object as parameter
  ----method invocation
  ----short circuit assignment
  ----shift operator
  ----floating point division and addition
  ----implicit type conversion
  ----nested for and switch
  ----non static member invocation


Operator used-
Arithmetic:++,+,%
Relational:<=,>,<
Bitwise:>>
Logical:
Assignment:=,<<=,-=,>>=.+=
Conditional:

keywords used:
class
    private
    double
    public
    static
    void
    int
    new
    while
    if
    else
    for
    switch
    case
    break
    default
*/

class abc
{
	private double arg1,arg2;			/*private member variables*/
	public abc(double a1)				/*overloaded constructors with double passed*/
	{
		arg1=a1;
		arg2=1.23;
	}

	public abc(double a1,double a2)
	{
		this(a1);				/*explicit constructor invocation*/
		arg2=a2;
	}
	
	public static void printer(abc obj)		/*object passed as a parameter*/
	{
		System.out.println(obj.arg1);		/*print statements---double value*/
		System.out.println(obj.arg2);
		System.out.println();
	}

	public static void main(String args[])
	{
		int a,b,c,d;				/*int variable declarations*/
		a=b=c=d=0;				/*multiple assignment*/
		abc o1=new abc(3.45);			/*overloaded constructor call*/
		abc o2=new abc(0.34,0.39);
		printer(o1);				/*method invocation*/
		printer(o2);
		int i,j,k,v = 1,n=23;				/*int variable declaration*/
        	while (v <= (n>>1)) 			/*while loop,relational operator,shift operator*/
            		v <<=1;				/*short circuit assignment--shift*/
        	while (v > 0) 				/*while loop with if statement embedded*/
		{
            		if (n < v) 			/*if else statement*/
                		System.out.print(0);
			else 
			{
                		System.out.print(1);
                		n -= v;			/*short circuit assignment--minus*/
            		}
			v>>=1;				/*short circuit assignment--shift operator*/
        	}
		System.out.println();	
		
		double sum = 0.0;			/*double initialisation*/
        	for (i = 1; i <= 10; i++) 
            		sum += 1.0 / i;			/*short circuit assignment==add,division of double,implicit casting*/
		System.out.println(sum);		/*printing a double*/
		for(i=1;i<=10;i++)			/*nested for*/
		{
			for(j=i;j<=10;j++)
			{
				for(k=j;k<=10;k++)
				{
					int x=i+j+k;			/*Variable Initialisation*/
					System.out.print(x);
					System.out.print(" is ");
					int v1=x%2;			/*mod operator*/
					switch(v1)			/*nested switch with break*/
					{
						case 0:System.out.print("divisible by 2");
							switch(x%4)
							{
								case 0:System.out.println(" and divisible by 4");
									break;
								case 2:switch(x%5)
									{
										case 0:System.out.println(" and divisible by 5");
											break;
										default:System.out.println(" and leaves remainder 2 from 4");
									}
									break;		/*break*/
							}
							break;
						default: System.out.print("an odd number");	/*default statement*/
							switch(x%3)
							{
								case 0:System.out.println(" and divisible by 3");	/*printing a string*/
									break;
								case 2:System.out.println(" and leaves remainder 2 from 3");
									break;
								case 1:System.out.println(" and leaves remainder 1 from 3");
									break;
							}
					}
				}
			}
		}
	}
}
