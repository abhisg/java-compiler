package abc

import java.util.*;
import java.io.IOException;

public class Erroneous {  
	int range = 0;
	public Erroneous () {
		range = 1000;
	}
	
	public static void main (String [] args) throws IOException {
		double ;
		Scanner sc = new Scanner (System.in);	
		System.out.println ("Enter a number ");
		int x = sc.readInt ();
	}

	public static int fact (int x) {
		if (x <= 1) return 1;
		return x * fact (x-1)
	}
}

