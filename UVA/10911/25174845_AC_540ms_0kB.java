import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.PreparedStatement;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	
	
	static double x[];
	static double y[];
	static String name[];
	static double dist[][];
	static int n;
	static double dp[];
	static final double  inf = 10000000.0;



	static void prepare_dist() {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n;j++) {
				if (i == j) continue;
				dist[i][j] = Math.hypot(x[i]-x[j],y[i]-y[j]);
			}
		}
	}

	static boolean is_full(int mask) {
		return (mask == (1<<n)-1);
	}


	static double solve(int mask) {
		if (is_full(mask)) return 0.0;
		if (dp[mask] != inf) return dp[mask];
		double x = inf;
		int par;
		for(int i = 0; i < n; i++) {
			if ((mask&(1<<i)) > 0) continue;
			for(int j = i + 1; j < n;j++) {
				if ((mask&(1<<j)) > 0) continue;
				par = ((1<<i)|(1<<j));
				x = Math.min(x, dist[i][j] + solve((mask|par)));
			}
		}

		return dp [mask] =  x;
	}
	
	
	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader();
		int cases = 1;
		while ((n = fr.nextInt()) != 0) {
			n *= 2;
			x = new double[n];
			y = new double[n];
			name = new String[n];
			dist = new double[n][n];
			dp = new double[1<<n];
			
			for(int i = 0; i < n; i++) {
				name[i] = fr.next();
				x[i] = fr.nextDouble();
				y[i] = fr.nextDouble();
			}
			
			Arrays.fill(dp, inf);
			prepare_dist();
			
			System.out.printf(Locale.ENGLISH,"Case %d: %.2f\n",cases,solve(0));
			cases ++;
			
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
