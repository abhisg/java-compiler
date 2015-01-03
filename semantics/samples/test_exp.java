class Test1 {
	public static void main(String[] args) {
		int i = 2;
		int j = (i=3) * i;
		System.out.println(j);
	}
}

class Test2 {
	public static void main(String[] args) {
		int a = 9;
		a += (a = 3); // first example
		System.out.println(a);
		int b = 9;
		b = b + (b = 3); // second example
		System.out.println(b);
	}
}

strictfp class Test5 {
	public static void main(String[] args) {
		double d = 8e+307;
		System.out.println(4.0 * d * 0.5);
		System.out.println(2.0 * d);
	}
}

class Test6 {

	static void print3(String a, String b, String c) {
		System.out.println(a + b + c);
	}
	public static void main(String[] args) {
		String s = "going, ";
		print3(s, s, s = "gone");
	}
}

class List {
	int value;
	List next;
	static List head;
	List(int n) { value = n; next = head; head = this; }
}

class Test {
	public static void main(String[] args) {
		int id = 0, oldid = 0;
			for (;;) {
				++id;
				new List(oldid = id);
			}
	}
}

class Test8 {
	public static void main(String[] args) {
		int i = 4;
		int ia[][] = new int[i][i=3];
}
}

public class Point1 {
	public int x, y;
	public Point1(int x, int y) 
	{ 	this.x = x; 
		this.y = y; 
	}
	public String toString(String s) {
		return "(" + "," + ")";
	}
	public String toString() { return toString(""); }
}

public class ColoredPoint1 extends Point1 {
	public static final int RED = 0, GREEN = 1, BLUE = 2;
	public static String[] COLORS ={ "red", "green", "blue" };
	public byte color;
	public ColoredPoint1(int x, int y, int color) {
		super(x, y);
		this.color = (byte)color;
	}
	public String toString() {
		String s = "," + COLORS[color];
		return super.toString(s);
	}
}

class Point2 {
	final int EDGE = 20;
	int x,y;
	void clear() {
		System.out.println("\tPoint clear");
		x = 0; y = 0;
	}
	void move(int dx, int dy) {
		x += dx; y += dy;
		if (x >= EDGE || y>= EDGE)
			clear();
	}
}
class ColoredPoint2 extends Point2 {
	int color;
	void clear() {
		System.out.println("\tColoredPoint clear");
		super.clear();
		color = 0;
	}
}

