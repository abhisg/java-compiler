/**---derived return type

operators used:
Arithmetic:+,-,*
Relational:
Bitwise:
Logical:
Assignment:=
Conditional:

keywords used:
 public
    class
    private
    final
    double
    this
    return
    new
    static
    void 
*/

public class Complex {
	/*private data members*/
    private final double re;   // the real part
    private final double im;   // the imaginary part

    // create a new object with the given real and imaginary parts
    public Complex(double real, double imag) {
        re = real;
        im = imag;
    }


    // return a new Complex object whose value is (this + b)
    Complex plus(Complex b) {					/*object passed as a parameter*/
        Complex a = this;             // invoking object
        double real = a.re + b.re;
        double imag = a.im + b.im;
        return new Complex(real, imag);					/*return an object*/
    }

    // return a new Complex object whose value is (this - b)
    public Complex minus(Complex b) {
        Complex a = this;					/*this keyword*/
        double real = a.re - b.re;
        double imag = a.im - b.im;
        return new Complex(real, imag);
    }

    // return a new Complex object whose value is (this * b)
    public Complex times(Complex b) {					/*overloaded function*/
        Complex a = this;
        double real = a.re * b.re - a.im * b.im;
        double imag = a.re * b.im + a.im * b.re;			/*precedence of operators*/
        return new Complex(real, imag);
    }

    // scalar multiplication
    // return a new object whose value is (this * alpha)
    public Complex times(double alpha) {				/*overloaded function*/
        return new Complex(alpha * re, alpha * im);
    }

    // return a new Complex object whose value is the conjugate of this
    //public Complex conjugate() {  return new Complex(re, -im); }
    public double re() { return re; }
    public double im() { return im; }

    
    


    // sample client for testing
    public static void main(String[] args) {
        Complex a = new Complex(5, 6);			//implicit casting
        Complex b = new Complex(-3, 4);			//implicit casting

        
        System.out.print("Re(a)= " );
	System.out.println( a.re());			/*method invocation*/
        System.out.print("Im(a)= ");
	System.out.println( a.im());
        System.out.print("Re(b)= " );
	System.out.println( b.re());
        System.out.print("Im(b)= ");
	System.out.println( b.im());
        Complex c=a.plus(b);
	Complex d=a.minus(b);
	Complex e=a.times(b);
	Complex f=a.times(4.09);

        System.out.print("Re(a+b)= " );
	System.out.println(c.re());
        System.out.print("Im(a+b)= " );
	System.out.println(c.im());
	
        System.out.print("Re(a-b)= " );
	System.out.println(d.re());
        System.out.print("Im(a-b)= " );
	System.out.println(d.im());
	
	System.out.print("Re(a*b)= " );
	System.out.println(e.re());
        System.out.print("Im(a*b)= " );
	System.out.println(e.im());

	System.out.print("Re(a*4.09)= " );
	System.out.println(f.re());
        System.out.print("Im(a*4.09)= " );
	System.out.println(f.im());
    }

}
/*public class Collatz {
    public static void collatz(int n) {
        System.out.print(n);
	System.out.print( " ");
        if (n == 1) return;
        else if (n % 2 == 0) collatz(n / 2);
        else collatz(3*n + 1);
    }

    public static void main(String[] args) {
        int N = 27;
        collatz(N);
        System.out.println();
    }

} */


