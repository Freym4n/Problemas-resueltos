import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;

		public FastReader() {
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

	
	static final int N = 100;
	static final int K = 100;
	static final int m = 1000000;
	static int dp[][] = new int[N][K];
	
	static void solve() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < K; j++) {
				if (j == 0) dp[i][j] = 1;
				else if (i == 0) dp[i][j] = j+1;
				else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%m;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader();
		int n = fr.nextInt()-1,k = fr.nextInt()-1;
		solve();
		while (n + k >= 0) {
			System.out.println(dp[n][k]);
			n = fr.nextInt()-1;
			k = fr.nextInt()-1;
		}
	}
}
