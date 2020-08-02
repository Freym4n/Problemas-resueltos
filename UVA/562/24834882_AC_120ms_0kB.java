import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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


	static int N;
	static int W;
	static boolean dp[][];
	static int a[];
	static int solve() {
		for(int i = 0; i < N + 1; i++) dp[i][0] = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < W + 1; j++) {
				if (dp[i][j]) dp[i+1][j] = dp[i+1][j + a[i]] = true;
			}
		}
		int mid = W/2;
		int result = W;
		for(int i = 0; i < W + 1; i++) {
			if (dp[N][i])
				result = Math.min(result, Math.abs(mid - i));
		}
		result *= 2;
		if ((W&1) > 0) result ++; 
		return result;
	}

	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader();
		int sum, cases;
		cases = fr.nextInt();
		for (int i = 0; i < cases; i++) {
			N = fr.nextInt();
			sum = 0;
			a = new int[N];
			for (int j = 0; j < N; j++) {
				a[j] = fr.nextInt();
				sum += a[j];
			}
			if (N == 0) {
				System.out.println(0);
				continue;
			}
			W = sum;
			dp = new boolean[N + 1][W + 1];
			System.out.println(solve());
		}
	}
}
