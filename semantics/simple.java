/**
  ---this keyword
  ---static and non static members
  ---recursive calls
  ---function overloading
  ---arrays as variables and arguments
  ---objects as member variable and function parameter
  ---calling member functions and accessing member variables
  ---ternary operator(nested)
  ---arithmetic operators,logical operators and relational operators
  ---while loops,for loops
  ---if else statements
  ---float operations and type conversion
  ---break keyword

operators used:
arithmetic:+,-,*,%,/,++
logical:||
relational:>,==,<,>,>=
bitwise:&
assignment:=(single and multiple)
ternary ?:


keywords used:
boolean
break
case
char
class
default
double
else
for
if
int
long
new
public
return
static
switch
this
void 
while
false
true
*/

class integers
{
	int prime,fact;

	public long factorial(int num)
	{
		return num==1?1:((num%this.prime)*(factorial(num-1)%this.prime))%this.prime;	/*recursive function call,ternary operator,this keyword*/
	}

	public static long gcd(long a,long b)
	{
		return (a==0 || b==0)?(a==0?b:a):(a>b?gcd(b,a%b):gcd(a,b%a));			/*logical operator,short circuit*/
	}	
        
	public long power(int a,int b,int c)
	{
		if(b==0)
			return 1;								/*return keyword*/
		long inter=power(a,b/2,c)%c;							/*recursive function call,shift operator,expression in actual parameter*/
		if((b&1)==0)									/*logical and*/
			return (inter*inter)%c;							/*implicit type conversion*/
		else
			return (a%c*((inter*inter))%c)%c;					/*mod operator*/
	}
	
	public long power(int a)
	{
		return power(a,this.prime-2,this.prime);					/*method invocation*/
	}
}

class floating
{
	static double val;
	double radius,reduce,expand;
	integers in;

	public double area()							/*function overloading*/
	{
		return ((val*radius*radius)/reduce)*expand;			/*arithmetic operators on double*/
	}

	public double area(floating obj)					/*object as a paramter*/
	{
		double value= ((val*obj.radius*obj.radius)/obj.reduce)*obj.expand;
		return value;					
	}
}

class simple
{
	static int size;
										/*overloaded function*/
	public static void sort(double []ar)					/*array as a paramter*/
	{
		int i,j;
		i=0;
		while(i<size)							/*nested while*/
		{
			j=0;
			while(j<size-i-1)			
			{
				if(ar[j]>ar[j+1])				/*if statement*/
				{
					double temp=ar[j];
					ar[j]=ar[j+1];
					ar[j+1]=temp;
				}
				j++;
			}
			i++;
		}
		System.out.println("sorted double array");
		i=0;
		while(i<size)
		{
			System.out.println(ar[i]);
			i++;
		}
		System.out.print("\n");
	}
	
	public static void sort(char []ar)					/*array as a paramter*/
	{
		int i,j;
		i=0;
		while(i<size)							/*nested while*/
		{
			j=0;
			while(j<size-i-1)			
			{
				if(ar[j]>ar[j+1])				/*if statement*/
				{
					char temp=ar[j];
					ar[j]=ar[j+1];
					ar[j+1]=temp;
				}
				j++;
			}
			i++;
		}
		System.out.println("sorted character array");
		i=0;
		while(i<size)
		{
			System.out.println(ar[i]);
			i++;
		}
		System.out.print("\n");
	}

	public static boolean binSearch(char []ar,char elem)			/*character array as parameter*/
	{
		int left=0,right=size-1;
		while(left<right)						/*while loop*/
		{
			int mid=(left+right)/2;
			if(ar[mid]==elem)			/*if else*/
				break;				/*break keyword*/
			else if(ar[mid]<elem)
				left=mid+1;
			else
				right=mid;
		}
		return left>=right?false:true;				/*ternary operator*/
	}

	public static void main(String args[])
	{
		integers numOp=new integers();				/*default constructor invocation*/
		floating[] areaOp=new floating[10];			/*new operator*/
		double[] ar={1,2.4,5.12,2.1,5,0.2,0.34};		/*array initialisation,implicit type casting*/
		char []arr={'c','a','e','5','1','0','f'};		/*character array initialisation*/
		size=7;
		floating.val=3.14;

		sort(ar);						/*method invocation*/
		sort(arr);

		switch(arr[2])						/*switch on array*/
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':System.out.print(arr[2]);
				System.out.println(" is a digit");
				break;
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':System.out.print(arr[2]);
				System.out.println(" is a vowel character");
				break;
			default:System.out.print(arr[2]);
				System.out.println(" is a consonant character");
		}
			
		int i=1;
		long a,b;
	
		numOp.prime=113;
		System.out.println("\ngcd of power,factorial from 1 to 12\n");
		while(i<=12)
		{
			a=numOp.power(i);				/*instance function call*/
			b=numOp.factorial(100+i);
			System.out.println(integers.gcd(a,b));		/*function call as an actual parameter*/
			i++;
		}
		System.out.println();
		i=1;
		for(;i<=10;i++)
		{
			areaOp[i-1]=new floating();			/*default constructor invocation*/
			areaOp[i-1].radius=1.01*i;		/*implicit type casting*/
			areaOp[i-1].reduce=2.02*i;
			areaOp[i-1].expand=4.32*i;
			areaOp[i-1].in=new integers();		/*derived member variable*/
			areaOp[i-1].in.prime=113;
			System.out.print(areaOp[i-1].in.power(i));	/*call through derived member variable*/
			System.out.print(" ");
			System.out.println(areaOp[i-1].in.factorial(100+i));
			System.out.println(areaOp[i-1].area());		/*overloaded function calls*/
			double value=areaOp[i-1].area(areaOp[i-1]);
			System.out.println(value);
		}
	}
}
