import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int dp[] = new int[77];
	
	static void solve() {
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 2;
		for (int i = 4; i < 77; i++) {
			dp[i] = dp[i-2] + dp[i-3]; 
		}
	}
	
	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader();
		int n;
		solve();
		while(fr.ready()) {
			n = fr.nextInt();
			System.out.println(dp[n]);
		}
		
	}
	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;

		public FastReader()  {
			bf = new BufferedReader(new InputStreamReader(System.in));
			
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
