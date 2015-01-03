//import java.io.OutputStream;
//import java.io.IOException;

class Z {
    static int j = 1;
    static int peek() { return j; }
    static int i = peek();
    
}

class UseBeforeDeclaration {
    static {
        static int x = 100;
          // ok - assignment
        int y = x + 1;
          // error - read before declaration
        int v = x = 3;
          // ok - x at left hand side of assignment
        int z = UseBeforeDeclaration.x * 2;
          // ok - not accessed via simple name
    }

    {
        int j = 200;
          // ok - assignment
        j = j + 1;
          // error - right hand side reads before declaration
        int k = j = j + 1;
          // error - illegal forward reference to j
        int n = j = 300;
          // ok - j at left hand side of assignment
        int h = j++;
          // error - read before declaration

    }

    int w = x = 3;
      // ok - x at left hand side of assignment
    int p = x;
      // ok - instance initializers may access static fields

    int m = j = 4;
      // ok - j at left hand side of assignment
}

class BufferOutput {
    private OutputStream o;
    BufferOutput(OutputStream o) { this.o = o; }
    protected byte[] buf = new byte[512];
    protected int pos = 0;
    public static void putchar(char c){
        buf[pos++] = (byte)c;
    }
    public static void flush(){
        pos = 0;
	BufferOutput.putchar('a');
    }
}
class LineBufferOutput extends BufferOutput {
    LineBufferOutput(OutputStream o) 
	{ super(o); }
    public void putchar(char c){
        super.putchar(c);
        if (c == '\n') flush();
    }
}
