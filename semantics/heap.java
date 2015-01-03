/**--static members
---function calls with arrays
---nested if else
---while loop
---break keyword
---boolean short circuit
---nested for
keywords used:
public
    class
    static
    int
    void
    if
    while
    else
    break
    new
    for
operators used:
Arithmetic:++,-,%,/,--,*,+
Relational:!=,>,==,<
Bitwise:
Logical:||,&&
Assignment:=,/=
Conditional:






*/

public class heap
{
	static int heapsize;			/*static data member*/

	static void insert(int ar[],int elem)	/*array passed as a parameter*/	
	{
		int temp;
		ar[heapsize]=elem;
		heapsize++;			/*post increment operator*/
		if(heapsize!=1)			/*if statement,!= operator*/
		{
			int loop=heapsize-1;
			while(loop>0)		/*while loop*/
			{
				temp=ar[loop];
				if(loop%2==0)			/*nested if else*/
				{
					if(ar[loop]>ar[loop/2-1])
					{
						ar[loop]=ar[loop/2-1];		/*expression inside array*/
						ar[loop/2-1]=temp;
						loop=loop/2-1;
					}
					else
						break;		/*break*/
				}
				else
				{
					if(ar[loop]>ar[loop/2])
					{
						ar[loop]=ar[loop/2];
						ar[loop/2]=temp;
						loop/=2;
					}
					else
						break;
				}
			}
		}
	}

	static void delete(int[] ar)
	{
		int temp=ar[heapsize-1];
		ar[--heapsize]=ar[0];			/*pre increment operator*/
		ar[0]=temp;
		int loop=0,x,y;
		while(loop*2+1<heapsize || loop*2+2<heapsize)	/*while loop*/
		{
			temp=ar[loop];
			x=loop*2+1;
			y=loop*2+2;
			if(x<heapsize && y<heapsize)		/*nested if else(deep nesting)*/
			{
				if(temp<ar[x] && temp<ar[y])
				{
					if(ar[y]>ar[x])
					{
						ar[loop]=ar[y];
						ar[y]=temp;
						loop=y;
					}
					else
					{
						ar[loop]=ar[x];
						ar[x]=temp;
						loop=x;
					}	
				}
				else if(ar[loop]<ar[y])
				{
					ar[loop]=ar[y];
					ar[y]=temp;
					loop=y;
				}
				else if(ar[loop]<ar[x])
                                {
                                        ar[loop]=ar[x];
                                        ar[x]=temp;
                                        loop=x;
                                }
				else 	
					break;			/*break*/
			}
			else if(x<heapsize)
			{
				if(ar[loop]<ar[x])
				{
					ar[loop]=ar[x];
					ar[x]=temp;
					loop=x;
				}
				else 
					break;
			}
			else if(y<heapsize)
			{
				if(ar[loop]<ar[y])
				{
					ar[loop]=ar[y];
					ar[y]=temp;
					loop=y;
				}
				else 	
					break;
			}
		}
	}

	public static void main(String args[])
	{
		int n=12,i,j;
		heapsize=0;					/*static member initialisation*/
		int []ar={3,1,4,0,-12,2,9,12,90,21,54,23};	/*array initialisation*/
		int []temp=new int[n];				/*new operator*/
		for(i=0;i<n;i++)				/*for loop*/
			insert(temp,ar[i]);
		for(i=0;i<n;i++)				/*nested for*/
		{
			delete(temp);
			System.out.print("after pass ");
			System.out.println(i+1);
			for(j=0;j<n;j++)
				System.out.println(temp[j]);
		}
	}
}

