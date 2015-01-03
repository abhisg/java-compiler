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

class Test3 {
	public static void main(String[] args) {
		int j = 1;
		try {
			int i = forgetIt() / (j = 2);
		} catch (Exception e) {
			System.out.println(e);
			System.out.println("Now j = " + j);
		}
	}
	static int forgetIt() throws Exception {
		throw new Exception("I'm outta here!");
	}
}


class Test4 {
	public static void main(String[] args) {
		int divisor = 0;
		try {
			int i = 1 / (divisor * loseBig());
		} catch (Exception e) {
			System.out.println(e);
		}
	}
	static int loseBig() throws Exception {
		throw new Exception("Shuffle off to Buffalo!");
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
	public static void main(String[] args) {
		String s = "going, ";
		print3(s, s, s = "gone");
	}
	static void print3(String a, String b, String c) {
		System.out.println(a + b + c);
	}
}

class Test7 {
	static int id;
	public static void main(String[] args) {
		try {
			test(id = 1, oops(), id = 3);
		} catch (Exception e) {
			System.out.println(e + ", id=" + id);
		}
	}
	static int test(int a, int b, int c) {
		return a + b + c;
	}
	static int oops() throws Exception {
		throw new Exception("oops");
	}
}

class IntVector {
	int[] v;
	boolean equals(IntVector other) {
		if (this == other)
			return true;
		if (v.length != other.v.length)
			return false;
		for (int i = 0; i < v.length; i++) {
			if (v[7] != other.v[i]) return false;
		}
		return true;
	}
}

class List {
	int value;
	List next;
	static List head = new List(0);
	List(int n) { value = n; next = head; head = this; }
}
class Test {
	public static void main(String[] args) {
		int id = 0, oldid = 0;
		try {
			for (;;) {
				++id;
				new List(oldid = id);
			}
		} catch (Error e) {
			List.head = null;
			System.out.println(e.getClass() + ", " + (oldid==id));
		}
	}
}

class Test8 {
	public static void main(String[] args) {
		int i = 4;
		int ia[][] = new int[i][i=3];
		System.out.println(
				"[" + ia.length + "," + ia[0].length + "]");
	}
}

class Test9 {
	public static void main(String[] args) {
		int[][] a = { { 00, 01 }, { 10, 11 } };
		int i = 99;
		try {
			a[val()][i = 1]++;
		} catch (Exception e) {
			System.out.println(e + ", i=" + i);
		}
	}
	static int val() throws Exception {
		throw new Exception("unimplemented");
	}
}

class Test10 {
	public static void main(String[] args) {
		int len = 0, oldlen = 0;
		Object[] a = new Object[0];
		try {
			for (;;) {
				++len;
				Object[] temp = new Object[oldlen = len];
				temp[0] = a;
				a = temp;
			}
		} catch (Error e) {
			System.out.println(e + ", " + (oldlen==len));
		}
	}
}

class S { int x = 0; }
class T extends S { int x = 1; }
class Test11 {
	public static void main(String[] args) {
		T t = new T();
		System.out.println("t.x=" + t.x + when("t", t));
		S s = new S();
		System.out.println("s.x=" + s.x + when("s", s));
		s = t;
		System.out.println("s.x=" + s.x + when("s", s));
	}
	static String when(String name, Object t) {
		return " when " + name + " holds a "
			+ t.getClass() + " at run-time.";
	}
}

class Test12 {
	static String mountain = "Chocorua";
	static Test3 favorite(){
		System.out.print("Mount ");
		return null;
	}
	public static void main(String[] args) {
		System.out.println(favorite().mountain);
	}
}

class ColoredPoint {
	int x, y;
	byte color;
	void setColor(byte color) { this.color = color; }
}
class Test {
	public static void main(String[] args) {
		ColoredPoint cp = new ColoredPoint();
		byte color = 37;
		cp.setColor(color);
		cp.setColor(37); // compile-time error
	}
}


public class Point {
	public int x, y;
	public Point(int x, int y) { this.x = x; this.y = y; }
	public String toString() { return toString(""); }
	public String toString(String s) {
		return "(" + x + "," + y + s + ")";
	}
}

public class ColoredPoint extends Point {
	public static final int
		RED = 0, GREEN = 1, BLUE = 2;
	public static String[] COLORS =
	{ "red", "green", "blue" };
	public byte color;
	public ColoredPoint(int x, int y, int color) {
		super(x, y);
		this.color = (byte)color;
	}
	/** Copy all relevant fields of the argument into
	  this ColoredPoint object. */
	public void adopt(Point p) { x = p.x; y = p.y; }
	public String toString() {
		String s = "," + COLORS[color];
		return super.toString(s);
	}
}

class Point {
	final int EDGE = 20;
	int x, y;
	void move(int dx, int dy) {
		x += dx; y += dy;
		if (Math.abs(x) >= EDGE || Math.abs(y) >= EDGE)
			clear();
	}
	void clear() {
		System.out.println("\tPoint clear");
		x = 0; y = 0;
	}
}
class ColoredPoint extends Point {
	int color;
	void clear() {
		System.out.println("\tColoredPoint clear");
		super.clear();
		color = 0;
	}
}

class Test1 {
public static void main(String[] args) {
Point p = new Point();
System.out.println("p.move(20,20):");
p.move(20, 20);
ColoredPoint cp = new ColoredPoint();
System.out.println("cp.move(20,20):");
cp.move(20, 20);
p = new ColoredPoint();
System.out.println("p.move(20,20), p colored:");
p.move(20, 20);
}
}class T1 {
String s() { return "1"; }
}
class T2 extends T1 {
String s() { return "2"; }
}
class T3 extends T2 {
String s() { return "3"; }
void test() {
System.out.println("s()=\t\t" + s());
System.out.println("super.s()=\t" + super.s());
System.out.println("((T2)this).s()=\t" + this.s());
System.out.println("((T1)this).s()=\t" + this.s());
}
}
class Test2 {
public static void main(String[] args) {
T3 t3 = new T3();
t3.test();
}
}

class Test3 {
public static void main(String[] args) {
int index = 1;
try {
nada()[index=2]++;
} catch (Exception e) {
System.out.println(e + ", index=" + index);
}
}
static int[] nada() { return null; }
}

class Test4 {
public static void main(String[] args) {
int[] a = null;
try {
int i = a[vamoose()];
System.out.println(i);
} catch (Exception e) {
System.out.println(e);
}
}
static int vamoose() throws Exception {
throw new Exception("Twenty-three skidoo!");
}
}

class Test1 {
public static void main(String[] args) {
int a = 5%3; // 2
int b = 5/3; // 1
System.out.println("5%3 produces " + a +
" (note that 5/3 produces " + b + ")");
int c = 5%(-3); // 2
int d = 5/(-3); // -1
System.out.println("5%(-3) produces " + c +
" (note that 5/(-3) produces " + d + ")");
int e = (-5)%3; // -2
int f = (-5)/3; // -1
System.out.println("(-5)%3 produces " + e +
" (note that (-5)/3 produces " + f + ")");
int g = (-5)%(-3); // -2
int h = (-5)/(-3); // 1
System.out.println("(-5)%(-3) produces " + g +
" (note that (-5)/(-3) produces " + h + ")");
}
}

class Bottles {
static void printSong(Object stuff, int n) {
String plural = (n == 1) ? "" : "s";
loop: while (true) {
System.out.println(n + " bottle" + plural
+ " of " + stuff + " on the wall,");
System.out.println(n + " bottle" + plural
+ " of " + stuff + ";");
System.out.println("You take one down "
+ "and pass it around:");
--n;
plural = (n == 1) ? "" : "s";
if (n == 0)
break loop;
System.out.println(n + " bottle" + plural
+ " of " + stuff + " on the wall!");
System.out.println();
}
System.out.println("No bottles of " +
stuff + " on the wall!");
}
public static void main(String[] args) {
printSong("slime", 3);
}
}

class ArrayReferenceThrow extends RuntimeException { }
class IndexThrow extends RuntimeException { }
class RightHandSideThrow extends RuntimeException { }
class IllustrateSimpleArrayAssignment {
static Object[] objects = { new Object(), new Object() };
static Thread[] threads = { new Thread(), new Thread() };
static Object[] arrayThrow() {
throw new ArrayReferenceThrow();
}
static int indexThrow() {
throw new IndexThrow();
}
static Thread rightThrow() {
throw new RightHandSideThrow();
}
static String name(Object q) {
String sq = q.getClass().getName();
int k = sq.lastIndexOf('.');
return (k < 0) ? sq : sq.substring(k+1);
}
static void testFour(Object[] x, int j, Object y) {
String sx = x == null ? "null" : name(x[0]) + "s";
String sy = name(y);
System.out.println();
try {
System.out.print(sx + "[throw]=throw => ");
x[indexThrow()] = rightThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print(sx + "[throw]=" + sy + " => ");
x[indexThrow()] = y;
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print(sx + "[" + j + "]=throw => ");
x[j] = rightThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print(sx + "[" + j + "]=" + sy + " => ");
x[j] = y;
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
}
public static void main(String[] args) {
try {
System.out.print("throw[throw]=throw => ");
arrayThrow()[indexThrow()] = rightThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print("throw[throw]=Thread => ");
arrayThrow()[indexThrow()] = new Thread();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print("throw[1]=throw => ");
arrayThrow()[1] = rightThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print("throw[1]=Thread => ");
arrayThrow()[1] = new Thread();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
testFour(null, 1, new StringBuffer());
testFour(null, 1, new StringBuffer());
testFour(null, 9, new Thread());
testFour(null, 9, new Thread());
testFour(objects, 1, new StringBuffer());
testFour(objects, 1, new Thread());
testFour(objects, 9, new StringBuffer());
testFour(objects, 9, new Thread());
testFour(threads, 1, new StringBuffer());
testFour(threads, 1, new Thread());
testFour(threads, 9, new StringBuffer());
testFour(threads, 9, new Thread());
}
}

class ArrayReferenceThrow extends RuntimeException { }
class IndexThrow extends RuntimeException { }
class RightHandSideThrow extends RuntimeException { }
class IllustrateCompoundArrayAssignment {
static String[] strings = { "Simon", "Garfunkel" };
static double[] doubles = { Math.E, Math.PI };
static String[] stringsThrow() {
throw new ArrayReferenceThrow();
}
static double[] doublesThrow() {
throw new ArrayReferenceThrow();
}
static int indexThrow() {
throw new IndexThrow();
}
static String stringThrow() {
throw new RightHandSideThrow();
}
static double doubleThrow() {
throw new RightHandSideThrow();
}

static String name(Object q) {
String sq = q.getClass().getName();
int k = sq.lastIndexOf('.');
return (k < 0) ? sq : sq.substring(k+1);
}
static void testEight(String[] x, double[] z, int j) {
String sx = (x == null) ? "null" : "Strings";
String sz = (z == null) ? "null" : "doubles";
System.out.println();
try {
System.out.print(sx + "[throw]+=throw => ");
x[indexThrow()] += stringThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print(sz + "[throw]+=throw => ");
z[indexThrow()] += doubleThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print(sx + "[throw]+=\"heh\" => ");
x[indexThrow()] += "heh";
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print(sz + "[throw]+=12345 => ");
z[indexThrow()] += 12345;
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print(sx + "[" + j + "]+=throw => ");
x[j] += stringThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print(sz + "[" + j + "]+=throw => ");
z[j] += doubleThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print(sx + "[" + j + "]+=\"heh\" => ");
x[j] += "heh";
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print(sz + "[" + j + "]+=12345 => ");
z[j] += 12345;
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
}

public static void main(String[] args) {
try {
System.out.print("throw[throw]+=throw => ");
stringsThrow()[indexThrow()] += stringThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print("throw[throw]+=throw => ");
doublesThrow()[indexThrow()] += doubleThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print("throw[throw]+=\"heh\" => ");
stringsThrow()[indexThrow()] += "heh";
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print("throw[throw]+=12345 => ");
doublesThrow()[indexThrow()] += 12345;
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print("throw[1]+=throw => ");
stringsThrow()[1] += stringThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print("throw[1]+=throw => ");
doublesThrow()[1] += doubleThrow();
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print("throw[1]+=\"heh\" => ");
stringsThrow()[1] += "heh";
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
try {
System.out.print("throw[1]+=12345 => ");
doublesThrow()[1] += 12345;
System.out.println("Okay!");
} catch (Throwable e) { System.out.println(name(e)); }
testEight(null, null, 1);
testEight(null, null, 9);
testEight(strings, doubles, 1);
testEight(strings, doubles, 9);
}
}
