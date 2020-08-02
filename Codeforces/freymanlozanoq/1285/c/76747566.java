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
	
	
	long X;
	final int max_int = 1000001;
	long gcd(long a, long b) {
		return b==0?a:gcd(b,a%b);
	}
	
	long lcm (long a, long b) {
		return a*b/gcd(a,b);
	}
	
	
	
	public void solve() throws IOException {
		X = in.nextLong();
		long a = 1, b = X,temp,temp2;
		for(int i = 2; i < max_int; i++) {
			temp = i;
			if (X%temp != 0) continue;
			temp2 = X/temp;
			if (temp2 == temp || Math.max(temp, temp2) >= Math.max(a, b)) continue;
			if (lcm(temp,temp2) != X) continue;
			a = temp;
			b = temp2;
		}
		out.println(a + " " + b);
		
	}





}
