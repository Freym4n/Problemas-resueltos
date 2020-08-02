import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
	
	static class Par implements Comparable<Par> {
		
		int id, index;
		
		public Par(int id, int index) {
			super();
			this.id = id;
			this.index = index;
		}
		public int compareTo(Par arg0) {
			if (this.id == arg0.id)
				return this.index - arg0.index;
			return this.id - arg0.id;
		}
	}
	
	static int[] last_index;
	static int last_answer;
	static int n,q;
	static TreeMap<Par, Integer> lst = new TreeMap<Par, Integer>();
	
	static void insert(int x, int y) {
		x = (x^last_answer)%n;
		Par p = new Par(x,last_index[x]);
		last_index[x] ++;
		lst.put(p, y);
		
	}
	
	static int find(int x, int y) { 
		x = (x^last_answer)%n;
		y = y%(last_index[x]);
		Par p = new Par(x, y);
		return last_answer = lst.get(p);
		
	}
	
	public static void main(String[] args) {
		FastReader fr = new FastReader();
		n = fr.nextInt();
		q = fr.nextInt();
		last_answer = 0;
		last_index = new int[n];
		int type,x,y;
		for (int i = 0; i < q; i++) {
			type = fr.nextInt();
			x = fr.nextInt();
			y = fr.nextInt();
			if (type == 1) {
				insert(x,y);
			} else  {
				System.out.println(find(x, y));
			}
		}
		
	}
	
	
	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;

		public FastReader() {
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
