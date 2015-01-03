public class test10 {

	static int size;
	public static void printer (int [] a) {
		int i = 0;
		while (i < size) {
			System.out.print ("a [");
			System.out.print (i);
			System.out.print ("] = ");
			System.out.print (a [i]);
			System.out.print ("\n");
			i++;
		}
	}


	//Bubble sort	
	public static void bubble (int [] a, int num) {

		boolean swapped = true;

		int i, temp1, temp2;

		while (swapped) {

			swapped = false;			
			i = 0;

			while (i < num - 1) {

				temp1 = a [i];
				temp2 = a [i+1];

				if (temp1 > temp2) {
					a [i+1] = temp1;
					a [i] = temp2;
					swapped = true;
				}

				i++;
			}

			num --;
		}

	}

	public void main () {
		System.out.println ("Bubble sort\n");

		int []a=new int[8];
		size=8;
		a [0] = 10;
		a [1] = 2;
		a [2] = 9;
		a [3] = 5;
		a [4] = 4;
		a [5] = 11;
		a [6] = 7;
		a [7] = 1;
	
		System.out.println ("Before sorting\n");
		printer (a);

		bubble (a,size);

		System.out.println ("After bubble sort\n");
		printer (a);
	}

}

