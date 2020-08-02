import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;

		public FastReader()  {
			bf = new BufferedReader(new InputStreamReader(System.in));
			//bf = new BufferedReader(new FileReader("p.txt"));
		}
		String next() {
			while(st == null || !st.hasMoreElements())
				try {
					st = new StringTokenizer(bf.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		int nextInt()  {
			return Integer.parseInt(next());
		}
		long nextLong()  {
			return Long.parseLong(next());
		}
		double nextDouble()  {
			return Double.parseDouble(next());
		}
		String nextLine() throws IOException {
			return bf.readLine();
		}
		boolean ready() throws IOException {
			return bf.ready() || (st != null && st.hasMoreElements());
		}
	}

	public static void main(String[] args) {
		FastReader fr = new FastReader();
		ArrayList<String> lst = new ArrayList<String>();
		int t, v, e; String to, from; int  w;
		t = fr.nextInt();
		for(int i = 0; i < t ; i++ ) {
			lst.clear();
			v = fr.nextInt();
			e = fr.nextInt();
			MST g = new MST(v, e);
			for(int j = 0; j < e; j++) {
				from = fr.next();
				to = fr.next();
				w = fr.nextInt();
				if (!lst.contains(from))
					lst.add(from);
				if (!lst.contains(to))
					lst.add(to);
				g.edge[j].from = lst.indexOf(from);
				g.edge[j].to = lst.indexOf(to);
				g.edge[j].w = w;
			}
			System.out.println(g.solve());
			System.out.print(i < t - 1?"\n":"");
		}
	}
}


class Edge implements Comparable<Edge>{
	int from, to, w;

	public int compareTo(Edge o) {
		return this.w - o.w;
	}
}

class MST {
	int parent[], rank[], V, E;
	Edge edge[];

	public MST(int v, int e) {
		super();
		V = v;
		E = e;
		parent = new int[V];
		rank = new int[V];
		edge = new Edge[E];
		for(int i = 0; i < E; i++)
			edge[i] = new Edge();
	}

	void make_sets() {
		for(int i = 0 ; i < V ;i++)
			parent[i] = i;
	}

	int find(int node) {
		if (parent[node] == node) return node;
		return parent[node] = find(parent[node]);
	}

	boolean union(int a, int b) {
		int pa = find(a);
		int pb = find(b);
		if (pa == pb)  return false;
		if (rank[pa] < rank[pb])
			parent[pa] = pb;
		else if (rank[pa] > rank[pb])
			parent[pb] = pa;
		else  {
			parent[pb] = pa;
			rank[pa] ++;
		}
		return true;
	}

	long solve() {
		Arrays.sort(edge);
		long result = 0;
		make_sets();
		int i = 0, j = 0;
		Edge e; boolean p;
		while (i < V - 1) {
			e = edge[j];
			p = union(e.from, e.to);
			j++;
			if (p) {
				i++;
				result += e.w;
			}
		}
		return result;
	}
}