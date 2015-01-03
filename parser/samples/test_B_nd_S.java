class Global {
	class Cyclic {}
	void foo() {
		new Cyclic(); // create a Global.Cyclic
		class Cyclic extends Cyclic {} // circular definition
		{
			class Local {}
			{
				class Local {} // compile-time error
			}
			class Local {} // compile-time error
			class AnotherLocal {
				void bar() {
					class Local {} // ok
				}
			}
		}
		class Local {} // ok, not in scope of prior Local
	}
}

public class Foo {
	public static void main(String[] args) {
		Baz.testAsserts();
		// Will execute after Baz is initialized.
	}
}
class Bar {
	static {
		Baz.testAsserts();
		// Will execute before Baz is initialized!
	}
}
class Baz extends Bar {
	static void testAsserts() {
		boolean enabled = false;
		assert enabled = true;
		System.out.println("Asserts " +
				(enabled ? "enabled" : "disabled"));
	}
}

class TooMany {
	static void howMany(int k) {
		switch (k) {
			case 1: System.out.print("one ");
			case 2: System.out.print("too ");
			case 3: System.out.println("many");
		}
	}
	public static void main(String[] args) {
		howMany(3);
		howMany(2);
		howMany(1);
	}
}

class TwoMany {
	static void howMany(int k) {
		switch (k) {
			case 1: System.out.println("one");
				break; // exit the switch
			case 2: System.out.println("two");
				break; // exit the switch
			case 3: System.out.println("many");
				break; // not needed, but good style
		}
	}
	public static void main(String[] args) {
		howMany(1);
		howMany(2);
		howMany(3);
	}
}

class stt{
	public static String toHexString(int i) {
		StringBuffer buf = new StringBuffer(8);
		do {
			buf.append(Character.forDigit(i & 0xF, 16));
			i >>>= 4;
		} while (i != 0);
		return buf.reverse().toString();
	}
}

class Graph {
	int edges[][];
	public Graph(int[][] edges) { this.edges = edges; }
	public Graph loseEdges(int i, int j) {
		int n = edges.length;
		int[][] newedges = new int[n][];
		for (int k = 0; k < n; ++k) {
edgelist:
			{
				int z;
search:
				{
					if (k == i) {
						for (z = 0; z < edges[k].length; ++z) {
							if (edges[k][z] == j) break search;
						}
					} else if (k == j) {
						for (z = 0; z < edges[k].length; ++z) {
							if (edges[k][z] == i) break search;
						}
					}

					// No edge to be deleted; share this list.
					newedges[k] = edges[k];
					break edgelist;
				} //search
				// Copy the list, omitting the edge at position z.
				int m = edges[k].length - 1;
				int ne[] = new int[m];
				System.arraycopy(edges[k], 0, ne, 0, z);
				System.arraycopy(edges[k], z+1, ne, z, m-z);
				newedges[k] = ne;
			} //edgelist
		}
		return new Graph(newedges);
	}
}

class Graph {
	int edges[][];
	public Graph(int[][] edges) { this.edges = edges; }
	public Graph loseEdges(int i, int j) {
		int n = edges.length;
		int[][] newedges = new int[n][];
edgelists:
		for (int k = 0; k < n; ++k) {
			int z;
search:
			{
				if (k == i) {
					for (z = 0; z < edges[k].length; ++z) {
						if (edges[k][z] == j) break search;
					}
				} else if (k == j) {
					for (z = 0; z < edges[k].length; ++z) {
						if (edges[k][z] == i) break search;
					}
				}
				// No edge to be deleted; share this list.
				newedges[k] = edges[k];
				continue edgelists;
			} //search
			// Copy the list, omitting the edge at position z.
			int m = edges[k].length - 1;
			int ne[] = new int[m];
			System.arraycopy(edges[k], 0, ne, 0, z);
			System.arraycopy(edges[k], z+1, ne, z, m-z);
			newedges[k] = ne;
		} //edgelists
		return new Graph(newedges);
	}
}

class Test {
	public static void main(String[] args) {
		Test t = new Test();
		synchronized(t) {
			synchronized(t) {
				System.out.println("made it!");
			}
		}
	}
}

class BlewIt extends Exception {
	BlewIt() { }
	BlewIt(String s) { super(s); }
}
class Test {
	static void blowUp() throws BlewIt { throw new BlewIt(); }
	public static void main(String[] args) {
		try {
			blowUp();
		} catch (RuntimeException r) {
			System.out.println("Caught RuntimeException");
		} catch (BlewIt b) {
			System.out.println("Caught BlewIt");
		}
	}
}

class BlewIt extends Exception {
	BlewIt() { }
	BlewIt(String s) { super(s); }
}
class Test {
	static void blowUp() throws BlewIt {
		throw new NullPointerException();
	}
	public static void main(String[] args) {
		try {
			blowUp();
		} catch (BlewIt b) {
			System.out.println("Caught BlewIt");
		} finally {
			System.out.println("Uncaught Exception");
		}
	}
}


