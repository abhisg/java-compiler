import java.util.*;
public class example
{
	/* this comment /* // /** ends here: */
	public static void main()
	{
		A obj = new A();

		obj.get();
		//check unicode escape and octal escape
		char ch1='\u1234';
		char ch2='\012';	/*This is an 
		//			octal escape*/
		char ch3='\'';		/*******This is a normal escape************/
		char ch='a';		/*Normal character*/
		//char ch4='asdd';	//This is an error

		/*switch(ch)
		{
			case 'a':
			default:short d=1;
		}
		/*Test the identifiers.
		  Check the data type*/
		int[] x_123={0_1_2_3_4_14,2  ,  0372,    0xDada_Cafe ,   1996 ,   0x00_FF__00_FF};
		long[] $y={0l,    0777L,    0x100000000L ,   2_147_483_648L  ,  0xC0B0L};
		float[] $123f={0XAb.ffp-12f,1e1f  ,  2.f  ,  .3f  ,  0f  ,  3.14f  ,  6.022137e+23f};
		double[] d_34_5={0x.12p-12,1e1 ,   2. ,   .3 ,   0.0 ,   3.14,    1e-9d ,   1e137};
		boolean res = (((3 >>> 2)+(4 << 2)-(2 >> 2)) > 5) && ((4 > 5 ? true:false) != (~4 == 5));

		/*Check the operators****
		  ***Arithmetic,logical and relational****/
		int test = 0;
		test &= test/4 % 2;
		test = test++ + --test;
		test =~test;
		/****Check the string constants*************/
		if(test & 1)
		  x=4	;//System.out.println("result=i \n \t \\ \" \' \034 \uffff"+obj.getName("Abhijit","Sharang"));
		else 
		if(test | 1)
			System.out.println("Print:\"My name is Abhijit\"");
		else
		{	x=5;
			try
			{
				System.out.print("Number"+1/0+"is real\n");
				//System.out.println("This string is invalid"+"you
				//	cannot break a string");
				//String s="\u12";
				System.out.println(s+"\tis\t\"invalid\"\n");
			}
			catch(x)
			{
				x=10;
			}
		}
	}
}
