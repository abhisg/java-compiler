/**----static member variables
  ----do while loops,for loops,while loops(nested)
  ----recursive and non recursive function calls
  ----function overloading
  ----boolean short circuit evaluation
  ----nested if else
  ----new keyword
  ----arrays
  ----relational and logical operators
  ----postfix operators,arithmetic operators
  ----return statement

operators:
Arithmetic:-,--,+,/,++
Relational:>=,<=,>,<,==
Bitwise:
Logical:!,&&,||
Assignment:=
Conditional:

keywords:
public
    class
    static
    void
    int
    do
    while
    if
    return
    while
    new
    else
    for
*/

public class arrays
{
	static int arr[],size;			/*static member variable*/

	public static void set(int value)	/*void method with int*/
	{
		size=value;			/*static variable initialisation*/
		int i=size-1;
		do				/*do while loop*/
		{
			arr[i]=size-i-1;	/*array access*/
			i--;			/*post decrement operator*/
		}while(i>=0);
	}

	public static void swap (int i, int j) 	
	{
		int temp = arr [i];		/*array access*/
		arr[i] = arr [j];
		arr [j] = temp;
	}
		
	public static void qsort (int m, int n) /*overloaded functions*/
	{
		if (n <= m) return;		/*return statement*/

		int key, i, j, k;
		k = (m + n) / 2;		/*integer division*/

		swap (m, k);			/*function call*/

		key = arr[m];
		i = m + 1;  
		j = n;

		while (i <= j) 			/*nested while loop*/
		{
			while (i<=n && arr[i]<=key) 	/*logical operators---boolean short circuit operator*/
				i++;  
			while (j >= m && arr[j] > key)
				j--;
			if( !(i >= j))  		/*not operator,relational operator*/		
				swap(i, j);
		}  
		if (j > m) swap(m, j);
		qsort(m, j-1);  			/*recursive calls*/
		if (j < m) j = m;
		qsort(j+1, n);
		return ;
	}

	
	public static void qsort (int m, int n,int pivot) 	/*overloaded function*/
	{
		if (n <= m) return;

		int key, i, j, k;
		swap (m, pivot);

		key = arr[m];
		i = m + 1;  
		j = n;

		while (i <= j) 
		{
			while (i<=n && arr[i]<=key) 
				i++;  
			while (j >= m && arr[j] > key)
				j--;
			if( i < j)  				
				swap(i, j);
		}  
		if (j > m) swap(m, j);
		qsort(m, j-1);  
		if (j < m) j = m;
		qsort(j+1, n);
		return ;
	}

	public static void mergeSort(int begin,int end)		/*recursive function*/
	{
        	int mid=(end+begin)/2;				/*integer division*/
        	if(begin==end-1 || begin>=end)			/*relational operator,logical operator,boolean short circuit*/
                	return;		
        	mergeSort(begin,mid);				/*recursive functions*/
        	mergeSort(mid,end);
        	int k,left,right=mid;				/*multiple variable declaration/initialisation*/
		k=left=begin;					/*multiple assignment*/
		int[] temp=new int[end-begin];			/*new operator*/
        	while(k<end)					/*while loop*/
        	{
                	if(left<mid && right<end)		/*nested if else*/
                	{
                        	if(arr[left]<=arr[right])
                        	{
                                	temp[k-begin]=arr[left];
					k++;			/*post increment operator*/
					left++;
                        	}
                        	else
                        	{
                                	temp[k-begin]=arr[right];
					k++;
					right++;
                        	}
                	}
                	else if(left>=mid)
                	{
                        	temp[k-begin]=arr[right];	/*expression inside array access*/
				k++;
				right++;
                	}
                	else
                	{
                        	temp[k-begin]=arr[left];
				k++;
				left++;
                	}
        	}
		for(k=begin;k<end;k++)				/*for loop*/
			arr[k]=temp[k-begin];
       }

	public static void main(String args[])
	{
		arr=new int[30];			/*new operator*/
		int i;

		set(10);				//normal quick sort
		i=0;			
		System.out.println("before");		/*method invocation*/
		while(i<size)				/*while loop*/
		{
			System.out.println(arr[i]);
			i++;
		}
		qsort(0,size-1);
		i=0;
		System.out.println("after");
		while(i<size)
		{
			System.out.println(arr[i]);
			i++;
		}

				
		set(20);				//quick sort with user defined pivot
		i=0;
		System.out.println("before");
		while(i<size)
		{
			System.out.println(arr[i]);
			i++;
		}
		qsort(0,size-1,5);			//quick sort with user defined pivot	/*expression inside arguments*/
		i=0;
		System.out.println("after");
		while(i<size)
		{
			System.out.println(arr[i]);
			i++;
		}

		
		set(30);				
		i=0;
		System.out.println("before");
		while(i<size)
		{
			System.out.println(arr[i]);
			i++;
		}
		mergeSort(0,size);
		i=0;
		System.out.println("after");
		while(i<size)
		{
			System.out.println(arr[i]);	/*array access*/
			i++;
		}
	}
}

