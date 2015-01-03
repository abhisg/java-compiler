/**derived data members
--constructor overloading

operators used:
arithmetic:*

keywords used:
class
int
new
public
private
return
static
this
void 
*/

public class Point {
    public int x = 0;
    public int y = 0;
	// a constructor!
    public Point(int a, int b) {		/*parameterised constructor*/
	x = a;
	y = b;
    }
}
public class Rectangle {
    public int width = 0;
    public int height = 0;
    public Point origin;		/*derived member variable*/

    // four constructors
    public Rectangle() {		/*constructor overloading*/
	origin = new Point(0, 0);
    }
    public Rectangle(Point p) {
	origin = p;
    }
    public Rectangle(int w, int h) {
	origin = new Point(0, 0);
	width = w;
	height = h;
    }
    public Rectangle(Point p, int w, int h) {
	origin = p;
	width = w;
	height = h;
    }

    // a method for moving the rectangle
    public void move(int x, int y) {				/*instance method*/	
	this.origin.x = x;
	this.origin.y = y;
    }

    // a method for computing the area of the rectangle
    public int getArea() {					/*instance method*/
	return width * height;
    }
}
public class CreateObjectDemo {

    public static void main(String[] args) {
		
        // Declare and create a point object and two rectangle objects.
        Point originOne = new Point(23, 94);
        Rectangle rectOne = new Rectangle(originOne, 100, 200);			/*object creation with overloaded constructor*/
        Rectangle rectTwo = new Rectangle(50, 100);
	
        // display rectOne's width, height, and area
        System.out.print("Width of rectOne: ");
	System.out.println( rectOne.width);
        System.out.print("Height of rectOne: ");
	System.out.println(  rectOne.height);			/*member variable access*/
        System.out.print("Area of rectOne: ");
	System.out.println( rectOne.getArea());
        // set rectTwo's position
        rectTwo.origin = originOne;
		
        // display rectTwo's position
        System.out.print("X Position of rectTwo: ");
	 System.out.println(rectTwo.origin.x);
        System.out.print("Y Position of rectTwo: ");
	System.out.println(  rectTwo.origin.y);
		
        // move rectTwo and display its new position
        rectTwo.move(40, 72);					/*function call*/
        System.out.print("X Position of rectTwo: " );
	System.out.println( rectTwo.origin.x);
        System.out.print("Y Position of rectTwo: ");
	System.out.println( rectTwo.origin.y);
    }
}
