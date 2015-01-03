public class test14 
{
	
	public void swap (int [] arr, int i, int j) {
		int temp = arr [i];
		arr[i] = arr [j];
		arr [j] = temp;
	}
	
	public static void printer (int [] a,int size) {
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

	public void qsort (int [] arr, int m, int n) {
		if (n <= m) return;

		int key, i, j, k;
		k = (m + n) / 2;

		swap (arr, m, k);

		key = arr[m];
		i = m + 1;  
		j = n;

		while (i <= j) {
			while (i<=n && arr[i]<=key) 
				i++;  
			while (j >= m && arr[j] > key)
				j--;
			if( i < j)  				
				swap(arr, i, j);
		}  
		// swap two elements
		if (j > m) swap(arr, m, j);
		// recursively sort the lesser arr
		qsort(arr, m, j-1);  
		if (j < m) j = m;
		qsort(arr, j+1, n);
		return ;
	}

	public void main () {
		System.out.print ("Quick sort\n\n");

		int x [] = {14,31,2,38,100,15};
		System.out.print ("Before sorting\n");
		printer (x, 6);

		qsort (x, 0, 5);

		System.out.print("After quicksort\n");
		printer (x, 6);
	}
}

