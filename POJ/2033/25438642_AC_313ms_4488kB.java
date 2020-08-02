import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;

		public FastReader()  {
			bf = new BufferedReader(new InputStreamReader(System.in));
			//bf = new BufferedReader(new FileReader("input.txt"));
		}

		String next() {
			while(st == null || !st.hasMoreElements())
				try { st = new StringTokenizer(bf.readLine());
				} catch (IOException e) { e.printStackTrace(); }
			return st.nextToken();
		}

		int nextInt()  { return Integer.parseInt(next()); }

		long nextLong()  { return Long.parseLong(next()); }

		double nextDouble()  { return Double.parseDouble(next()); }

		String nextLine() throws IOException { return bf.readLine(); }

		boolean ready() throws IOException { return bf.ready(); }

		void close() throws IOException {	bf.close(); }
	}

	public static void main(String[] args) throws IOException  {
		FastReader fr = new FastReader();
		Main m = new Main();
		m.solve(fr);
		fr.close();
	}

	class Pair implements Comparable<Pair> {
		int x, y;

		public int compareTo(Pair arg0) {
			if (this.x == arg0.x)
				return (this.y - arg0.y);//*(-1);
			return (this.x - arg0.x);//*(-1);
		}

		public Pair(int id, int w) {
			this.x = id;
			this.y = w;
		}

		public String toString() {	
			return "( "+x+" , "+y+" )"; 
		}
	}

	String in;
	long dp[];
	char s[];
	int n;
	
	int get(char a, char b) {
		return Integer.parseInt(a + ""+ b);
	}
	
	public void solve(FastReader fr) throws IOException {
		int value;
		while(!(in = fr.next()).equals("0")) {
			n = in.length();
			s = in.toCharArray();
			dp = new long[n];
			dp[0] = 1;
			for(int i = 1; i < n; i++) {
				if (s[i] != '0') dp[i] = dp[i-1];
				value = get(s[i-1],s[i]);
				if (value > 26 || s[i-1] == '0') continue;
				if (i == 1) dp[i]++;
				else dp[i] += dp[i-2];
			}
			System.out.println(dp[n-1]);
		}
	
	}





}
