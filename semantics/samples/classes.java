interface Colorable 
{
    void setColor(int color);
    int getColor();
}
interface Paintable extends Colorable 
{
    void setFinish(Finish finish);
    int getFinish();
}

class Point 
{ 
	int x, y; 
	Point(int x,int y)
	{
		this.x=x;
		this.y=y;
	}
	void printX()
	{
		System.out.println(x);
	}
}
class ColoredPoint extends Point implements Colorable 
{
    int color;
    public void setColor(int color) { this.color = color; }
    public int getColor() { return color; }
}
class PaintedPoint extends ColoredPoint implements Paintable {
    int finish;
    public void setFinish(int finish) 
    {
        this.finish = finish;
    }
    public int getFinish() { return finish; }
}
class Test extends Point 
	{
    		public static void main(String[] args) {
        		new Point(2,3).printX();
		}
    	}	
