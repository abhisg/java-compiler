import java.io.*;

class StaticallyThrownExceptionsIncludeSubtypes {
    public static void main(String[] args) {
        try {
            throw new FileNotFoundException();
        } catch (IOException ioe) {
            // Legal in Java SE 6 and 7. "catch IOException"
            // catches IOException and any subtype.
        }

        try {
            throw new FileNotFoundException();
              // Statement "can throw" FileNotFoundException.
              // It is not the case that statement "can throw"
              // a subtype or supertype of FileNotFoundException.
        } catch (FileNotFoundException fnfe) {
            // Legal in Java SE 6 and 7.
        } catch (IOException ioe) {
            // Legal in Java SE 6 and 7, but compilers are
            // encouraged to throw warnings as of Java SE 7.
            // All subtypes of IOException that the try block
            // can throw have already been caught.
        }

        try {
            m();
              // Method m's declaration says "throws IOException".
              // m "can throw" IOException. It is not the case
              // that m "can throw" a subtype or supertype of
              // IOException, e.g. Exception, though Exception or
              // a supertype of Exception can always be caught.
        } catch (FileNotFoundException fnfe) {
            // Legal in Java SE 6 and 7, because the dynamic type
            // of the IOException might be FileNotFoundException.
        } catch (IOException ioe) {
            // Legal in Java SE 6 and 7.
        } catch (Throwable t) {
            // Legal in Java SE 6 and 7.
        }
    }

    static void m() throws IOException {
        throw new FileNotFoundException();
    }
}
class TestException extends Exception {
    TestException()         { super(); }
    TestException(String s) { super(s); }
}

class Test {
    public static void main(String[] args) {
        for (String arg : args) {
            try {
                thrower(arg);
                System.out.println("Test \"" + arg +
                                   "\" didn't throw an exception");
            } catch (Exception e) {
                System.out.println("Test \"" + arg +
                                   "\" threw a " + e.getClass() +
                                   "\n    with message: " +
                                   e.getMessage());
            }
        }
    }
    static int thrower(String s) throws TestException {
        try {
            if (s.equals("divide")) {
                int i = 0;
                return i/i;
            }
            if (s.equals("null")) {
                s = null;
                return s.length();
            }
            if (s.equals("test")) {
                throw new TestException("Test message");
            }
            return 0;
        } finally {
            System.out.println("[thrower(\"" + s + "\") done]");
        }
    }
}
