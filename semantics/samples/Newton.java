class Newton {

    // return the square root of c, computed using Newton's method
    public static double sqrt(double c) {
        double EPS = 0.0001;
        double t = c;
        while (t - c/t > EPS )
	{
            t = (c/t + t) / 2.0;
		//System.out.println(t-c/t);
	}
        return t;
    }

    // overloaded version in which user specifies the error tolerance EPS
    public static double sqrt(double c, double EPS){ 
        double t = c;
        while (t - c/t > EPS)
	{
            t = (c/t + t) / 2.0;
		//System.out.println(t-c/t);
	}
        return t;
    }


    // test client
    public static void main(String[] args) {

        // parse command-line parameters
	int i;
        double[] a = new double[10];
        for (i = 0; i < 10; i++) {
            a[i] = i+1.1;
        }

        // compute square root for each command line parameter
        for (i = 0; i < 10; i++) {
            double x = sqrt(a[i],0.01)>=sqrt(a[i])?a[i]<1?sqrt(a[i],0.01):sqrt(a[i]):sqrt(a[i]);
            System.out.println(x);
        }
    }
}
