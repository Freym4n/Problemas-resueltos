import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int dp[][];
	static boolean abc[];
	static char[] s;
	static int last[];
	static int n;
	static final int m = 3;
	static int solve(String t) {
		s = t.toCharArray();
		n = s.length;
		abc = new boolean[26];
		dp = new int[m][n];
		dp[0][0] = 1;
		abc[s[0]-65] = true;
		for(int i = 1; i < n; i++) {
			dp[0][i] = dp[0][i-1];
			if (!abc[s[i]-65]) {
				dp[0][i] ++;
				abc[s[i]-65] = true;
			}
		}
		int li;
		for(int i = 1; i < m; i++) {
			last = new int[26];
			for ( int j = i; j < n; j++) {
				dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
				li = last[s[j]-65];
				if (li != 0 ) 
					dp[i][j] -= dp[i-1][li-1];
				last[s[j]-65] = j;
			}
		}
		return dp[m-1][n-1];
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		FastReader fr = new FastReader();
		int t = fr.nextInt();
		for(int i = 0; i < t;i++) {
			System.out.println(solve(fr.next()));
		}
	}
	
	
	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;

		public FastReader() throws FileNotFoundException  {
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
	}

	
}
