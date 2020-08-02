import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	class FastReader {
		BufferedReader bf;
		StringTokenizer st;
		public FastReader()  {
			bf = new BufferedReader(new InputStreamReader(System.in));
			//bf = new BufferedReader(new FileReader("input.txt"));
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
		void close() throws IOException {
			bf.close();
		}

	}
	public static void main(String[] args) throws IOException  {
		Main m = new Main();
		m.solve();
		m.in.close();
		m.out.close();
	}
	PrintWriter out = new PrintWriter(System.out);
	FastReader in = new FastReader();
	class Pair implements Comparable<Pair>{
		int x; int y;
		@Override
		public int compareTo(Pair arg0) {
			if (this.x == arg0.x)
				return this.y - arg0.y;
			return this.x - arg0.x;
		}
		public Pair(int id, int w) {
			super();
			this.x = id;
			this.y = w;
		}
	}
	
	final int max = 800001;
	long parent[] = new long[max];
	int n;
	
	int get_parent(int idx, int value) {
		return n - idx + value;
	}

	public void solve() throws IOException {
		n = in.nextInt();
		int  b[] = new int[n];
		for(int i = 0; i <n; i++) {
			b[i] = in.nextInt();
			parent[get_parent(i,b[i])] += b[i];
		}
		long ans = 0;
		for(int i = 0; i < max; i++) {
			ans = Math.max(ans, parent[i]);
		}
		System.out.println(ans);
	}





}
