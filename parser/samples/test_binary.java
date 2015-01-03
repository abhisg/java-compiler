class Hyper { char h = 'h'; }
class Super extends Hyper { char s = 's'; }
class Test extends Super {
public static void printH(Hyper h) {
System.out.println(h.h);
}
public static void main(String[] args) {
printH(new Super());
}
}

class Hyper {
void hello() { System.out.println("hello from Hyper"); }
}
class Super extends Hyper {
void hello() { System.out.println("hello from Super"); }
}
class Test {
public static void main(String[] args) {
new Super().hello();
}
}

class Hyper {
void hello() { System.out.println("hello from Hyper"); }
}
class Super extends Hyper { }
class Test extends Super {
public static void main(String[] args) {
new Test().hello();
}
void hello() {
super.hello();
}
}

public class Point {
public int x, y;
protected void print() {
System.out.println("(" + x + "," + y + ")");
}
}

class Test extends points.Point {
public static void main(String[] args) {
Test t = new Test();
t.print();
}
protected void print() {
System.out.println("Test");
}
}

class Hyper { String h = "hyper"; }
class Super extends Hyper { String s = "super"; }
class Test {
public static void main(String[] args) {
System.out.println(new Super().h);
}
}

class Hyper { String h = "Hyper"; }
class Super extends Hyper { }
class Test extends Super {
public static void main(String[] args) {
String s = new Test().h;
System.out.println(s);
}
}

class Hyper { String h = "Hyper"; }
class Super extends Hyper { char h = 'h'; }
class Test extends Super {
public static void main(String[] args) {
String s = new Test().h;
System.out.println(s);
}
}

class Super { static char s; }
class Test extends Super {
public static void main(String[] args) {
s = 'a';
System.out.println(s);
}
}

class Flags { static final boolean debug = true; }
class Test {
public static void main(String[] args) {
if (Flags.debug)
System.out.println("debug is true");
}
}

interface Flags { boolean debug = true; }
class Test {
public static void main(String[] args) {
if (Flags.debug)
System.out.println("debug is true");
}
}

class Super { void out() { System.out.println("Out"); } }
class Test extends Super {
public static void main(String[] args) {
Test t = new Test();
System.out.println("Way ");
t.out();
}
}

class Super { void out() { System.out.println("out"); } }
class Test extends Super {
public static void main(String[] args) {
Test t = new Test();
t.out();
}
void out() { super.out(); }
}

class Super {
static void out(float f) {
System.out.println("float");
}
}
class Test {
public static void main(String[] args) {
Super.out(2);
}
}

interface I { void hello(); }
class Test implements I {
public static void main(String[] args) {
I anI = new Test();
anI.hello();
}
public void hello() { System.out.println("hello"); }
}


