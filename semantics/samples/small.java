public class ABC
{
	int arr[];
	public ABC(int ar[])
	{
		arr=ar;
	}
	public static void main(String args[])
	{
		int[] ar={1,2,3};
		ABC a=new ABC(ar);
		a.arr[0]=1;
	}	
}
