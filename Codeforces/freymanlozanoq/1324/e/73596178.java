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

	static int l,r,h,n;

	static int dp[][];
	static boolean v[][];
	static int a[];

	static boolean is_good(int value) {
		return value >= l && value <= r;
	}

	static int solve() {
		v[0][0] = true;
		int x1,x2;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < h; j++) {
				if (!v[i][j]) continue;
				x1 = (j + a[i])%h;
				x2 = (j + a[i] - 1)%h;
				v[i+1][x1] = v[i+1][x2]= true;
				dp[i+1][x1] = Math.max(dp[i+1][x1], dp[i][j] + (is_good(x1)?1:0));
				dp[i+1][x2] = Math.max(dp[i+1][x2], dp[i][j] +  (is_good(x2)?1:0));
			}
		int max = -1;
		for(int i = 0; i < h; i++ )
			max = Math.max(max, dp[n][i]);
		return max;
	}
	public static void main(String[] args) {
		FastReader fr = new FastReader();
		n = fr.nextInt();
		h = fr.nextInt();
		l = fr.nextInt();
		r = fr.nextInt();
		dp = new int[n+1][h];
		v = new boolean[n+1][h];
		a = new int[n];
		for (int i = 0; i < n; i++) 
			a[i] = fr.nextInt();
		System.out.println(solve());
	}
}
