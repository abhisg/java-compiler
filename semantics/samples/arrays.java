class Point 
{ 
	int x, y; 
	public Point()
	{
		x=0;
		y=0;
	}
}
class ColoredPoint extends Point 
{ 
	int color; 
}
class Test {
    public static void main(String[] args) {
        Point[] pa = new Point[10];
        //Point[] pa = cpa;
        //System.out.println(pa[1] == null);
        //try {
            pa[0] = new Point();
        //} catch (ArrayStoreException e) {
        //    System.out.println(e);
        //}
    }
}
class Test2 extends Test {
    public static void main(String[] args) {
        int ia[][] = { {1, 2}, {1,2} };
        for (int[] ea = ia[0];;) {
            for (int e= ea[0];;) {
                System.out.println(e);
            }
        }
    }
}

class Test1 {
    public static void main(String[] args) {
        int ia1[] = { 1, 2 };
        int ia2[] = {1,2};
        System.out.print((ia1 == ia2));
        ia1[1]++;
        System.out.println(ia2[1]);
    }
}

