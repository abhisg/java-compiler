/**--inheritance
---Liskov substitution principle
---parameterised constructor
---explicit constructor invocation(super and this)
---this operator
---method overriding


operators used:

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

class Bicycle 
{
        public int gear;
	public int cadence;
    	public int speed;
        public static int information;
    
	public Bicycle()							/*overloaded constructor*/
	{
		System.out.println("this object is initialised with the default constructor");
		gear=2;
		cadence=2;
		speed=20;
	}
	
    	public Bicycle(int startCadence, int startSpeed, int startGear) 	/*parameterised constructor*/
	{
        	System.out.println("this object is initialised with the parameterised constrcutor");
		this.gear = startGear;
        	this.cadence = startCadence;
        	this.speed = startSpeed;
    	}
        
     	public void printDescription()
	{
    		System.out.print("Bike is in gear ");
		System.out.print(  this.gear);				/*this keyword*/
        	System.out.print( " with a cadence of ");
		System.out.print( cadence);				/*member variable access*/
        	System.out.print(" and travelling at a speed of ");
		System.out.println( this.speed);
	}   
}

class MountainBike extends Bicycle 				/*inheritance*/
{
	public MountainBike(int startCadence,int startSpeed,int startGear)
	{
        	super(startCadence,startSpeed,startGear);		/*call to constructor of super class*/
        }
    	public void printDescription() 				
	{
        	super.printDescription();				/*super keyword*/
        }
}	 
 class RoadBike extends Bicycle
{
    // In millimeters (mm)
    	private int tireWidth;
	public void setTireWidth(int newTireWidth)
	{
        	this.tireWidth = newTireWidth;
    	}
    	public RoadBike(int startCadence,int startSpeed,int startGear,int newTireWidth)
	{
        	super(startCadence,startSpeed,startGear);		/*overloaded constrcutor*/
		Bicycle.information=newTireWidth;			/*call to static member*/
        	this.setTireWidth(Bicycle.information);
    	}
	public int getTireWidth()
	{
      		return this.tireWidth;
    	}
	public void printDescription()					/*polymorphism---method overriding*/
	{
        	super.printDescription();
        	System.out.print("The RoadBike has ");
		System.out.print( getTireWidth());
         	System.out.println(" MM tires.");
    	}
}
public class TestBikes 
{
	public static void main(String[] args)
	{
    		Bicycle bike01,bike02,bike03;
    		RoadBike bike04;					//object of inherited class
    		bike01 = new Bicycle();					/*Liskov substitution principle*/
    		bike02 = new MountainBike(20, 10, 5);			
    		bike03 = new RoadBike(40, 20, 8, 23);
		bike01.printDescription();
		System.out.println();
    		bike02.printDescription();
		System.out.println();
    		bike03.printDescription();
		System.out.println();


		System.out.println("This bike is a roadbike");
		bike04=new RoadBike(12,13,14,15);			//members are inherited by this object
		bike04.printDescription();				//call to overloaded method

		System.out.print("The inherited class modified the static member value to:");
		System.out.println(Bicycle.information);
  	}
}
