class TooMany {
	static void howMany(int k) 
	{
		switch (k) 
		{
			case 1: System.out.print("one ");
			case 2: System.out.print("too ");
			case 3: System.out.println("many");
			default:System.out.println("none");
		}
	}
	public static void main(String[] args) {
		howMany(3);
		howMany(2);
		howMany(1);
	}
}

class TwoMany {
	static void howMany(int k) 
	{
		switch (k) 
		{
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
class Graph {
	int edges[][];
	public Graph(int[][] edges) 
	{ 
		this.edges = edges; 
	}
	public Graph loseEdges(int i, int j) 
	{
		int n = 5;
		int[][] newedges = new int[n][];
edgelists:
		for (int k = 0; k < n; ++k) 
		{
			int z;
search:
			{
				if (k == i) 
				{
					for (z = 0; z < 10; ++z) 
					{
						if (edges[k][z] == j) break search;
					}
				} else if (k == j) 
				{
					for (z = 0; z < 10; ++z) 
					{
						if (edges[k][z] == i) break search;
					}
				}
				// No edge to be deleted; share this list.
				newedges[k] = edges[k];
				continue edgelists;
			} //search
			// Copy the list, omitting the edge at position z.
			int m = 9;
			int ne[] = new int[m];
			//System.arraycopy(edges[k], 0, ne, 0, z);
			//System.arraycopy(edges[k], z+1, ne, z, m-z);
			newedges[k] = ne;
		} //edgelists
		return new Graph(newedges);
	}
}
class BlewIt extends Graph{
	BlewIt() { }
	BlewIt(int edges[][]) { super(edges); }
}
