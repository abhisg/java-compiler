
public class test12 {
	//Towers of Hanoi puzzle
	public void toh (int s, int d, int temp, int n) {
		if (n <= 0) return;
		toh (s, temp, d, n-1);
		System.out.print ("Move disk from peg ");
		System.out.print (s);
		System.out.print (" to peg ");
		System.out.println (d);
		toh (temp, d, s, n-1);
	}

	public void main () {
		System.out.println ("Towers of Hanoi\n\n");
		
		toh (1, 3, 2, 4);
	}
}
