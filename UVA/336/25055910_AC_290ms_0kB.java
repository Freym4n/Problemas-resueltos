import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;



public class Main {

	static int e;
	static int id[];
	static par lst_edges[];
	static boolean v[];
	static ArrayList<Integer> lst[];

	static void bfs(int from, int tle) {
		Arrays.fill(v, false);
		Queue<item> q = new LinkedList<item>();
		q.add(new item(from,tle));
		v[from] = true;
		item t;
		while(!q.isEmpty()) {
			t = q.poll();
			if (t.tle == 0) continue;
			for(int i: lst[t.from]) {
				if (!v[i]) {
					v[i] = true;
					q.add(new item(i,t.tle-1));
				}
			}
		}
	}


	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader();
		int to, from,size,tle,cont,cases = 1;
		par t;
		Set<Integer> set = new TreeSet<Integer>();
		while ((e = fr.nextInt()) != 0) {
			set.clear();
			lst_edges = new par[e];
			for (int i = 0; i < e; i++) {
				from = fr.nextInt();
				to = fr.nextInt();
				lst_edges[i] =  new par(from,to);
				set.add(from);
				set.add(to);
			}
			size = set.size();
			id = new int[size];
			v = new boolean[size];
			int index = 0;
			for(Integer i: set) {
				id[index] = i;
				index++;
			}
			lst = new ArrayList[size];
			for(int i = 0; i < size; i++) {
				lst[i] = new ArrayList<Integer>();
			}
			for(int i = 0; i < e; i++) {
				t = lst_edges[i];
				to = Arrays.binarySearch(id, t.to);
				from = Arrays.binarySearch(id, t.from);
				lst[to].add(from);
				lst[from].add(to);
			}
			from = fr.nextInt();
			tle = fr.nextInt();
			while (from + tle > 0) {
				bfs(Arrays.binarySearch(id, from),tle);
				cont = 0;
				for(int i = 0; i < size; i++)
					if (!v[i]) cont++;
				System.out.println("Case " + cases + ": " + cont + " nodes not reachable from node " + from + " with TTL = " + tle + ".");
				cases ++;
				from = fr.nextInt();
				tle = fr.nextInt();
			}
		}	
	}

	static class item {
		int from, tle;

		public item(int from, int tle) {
			super();
			this.from = from;
			this.tle = tle;
		}
		
	}
 	static class par {
		int to,from;

		public par(int to, int from) {
			super();
			this.to = to;
			this.from = from;
		}

	}
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

}
