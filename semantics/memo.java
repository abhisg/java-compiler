/**----static members
  ----nested for statement
  ----arrays
  ----arithmetic operators

keywords used:
 public
    class
    static
    int
    void
    new
    while
    if
    return
    for

operators used:
Arithmetic:-,++,+,*
Relational:<,==,!=
Bitwise:
Logical:||
Assignment:=
Conditional:
*/

public class memo
{
	static int num,MOD;		/*static members*/
	static int[] fibo,prime;	/*static array*/
	
	public static void set()
	{
		int i=0;
		fibo=new int[num];		/*new operator*/
		prime=new int[num];
		while(i<num)			/*while loop*/
		{
			fibo[i]=-1;
			prime[i]=0;
			i++;			/*post increment operator*/
		}
	}

	public static void computeFibo(int num)
	{
		if(num==0 || num==1)
		{
			fibo[num]=1;
			return;				/*return statement*/
		}
		if(fibo[num]!=-1)
			return;
		computeFibo(num-1);			/*recursive function call*/
		computeFibo(num-2);
		fibo[num]=(fibo[num-1]+fibo[num-2]);
	}
	
	public static void primeSieve()
	{
		int i=2;
		for(;i<num;i++)			/*nested for*/
		{
			if(prime[i]==0)
				prime[i]=1;
			int c=2;
			int mul = i*c;
			for(;mul<num;c++,mul=i*c)
				prime[mul] = -1;
		}
	}

	public static void main(String args[])
	{
		num=MOD=13;				/*multiple assignment*/
		set();
		computeFibo(num-1);
		primeSieve();
		int i=0;
		while(i<num)				/*while loop*/
		{
			System.out.print("fibonacci number ");
			System.out.print(i);
			System.out.print("=");
			System.out.println(fibo[i]);
			if(prime[i]==1)			/*if statement*/
			{
				System.out.print(i);
				System.out.println(" is a prime number");
			}
			i++;
		}
	}
}
		
