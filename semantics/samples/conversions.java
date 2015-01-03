class Test {			
    public static void main(String[] args) {
        int big = 1234567890;
        float approx = big;
        System.out.println(big - (int)approx);
        short s;
        float f = s;       // widen short to float
        //System.out.println("f=" + f);
        char c = '\u0123';
        long l = c;        // widen char to long
        //System.out.println("l=0x" + Long.toString(l,16));
        f = (float)1.23f;
        double d = f;      // widen float to double
        //System.out.println("d=" + d);
    }
}
class Point 
{ 
	int x, y; 
	public Point()
	{
		x=0;
		y=0;
	}
}
class Point3D extends Point 
{ 
	int z; 
	public Point3D()
	{
		z=0;
	}
}
interface Colorable 
{ 
	void setColor(int color); 
}

class ColoredPoint extends Point implements Colorable 
{
    int color;
    public void setColor(int color) 
    { 
	this.color = color; 
    }
}

class Test4 {
    public static void main(String[] args) {
        // Assignments to variables of class type:
        Point p = new Point();
        int[] a   = new int[3];
        // Assignments to variables of interface type:
        ColoredPoint cp = new ColoredPoint();
        // Assignments to variables of array type:
        byte[] b = new byte[4];
        a = b;
          // Error: these are not arrays of the same primitive type
        Point3D[] p3da = new Point3D[3];
    }
}

class Test5 {
    public static void main(String[] args) {
        long[] veclong = new long[100];
        Long l = veclong;            // compile-time error
        short[] vecshort = veclong;  // compile-time error
        Point[] pvec = new Point[100];
        ColoredPoint[] cpvec = new ColoredPoint[100];
        pvec[0] = new Point();       // okay at compile time,
                                     // but would throw an
                                     // exception at run time
        cpvec = pvec;                // compile-time error
    }
}

