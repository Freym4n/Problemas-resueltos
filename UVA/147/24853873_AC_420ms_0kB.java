import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {

	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;

		public FastReader() throws FileNotFoundException {
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
	static int coin[] = {1,2,4,10, 20,40,100,200,400,1000,2000};
	static int n = 6002;
	static long amount[] = new long[n];
	
	static void solve() {
		amount[0] = 1;
		for (int c : coin) 
			for (int i = c; i < n; i++)
				amount[i] += amount[i-c];
	}
	
	
	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader();
		double in;
		int x;
		solve();
		while ((in = fr.nextDouble()) != 0.0) {
			in *= 20.0;
			x = (int) in;
			in/= 20.0;
			System.out.printf(Locale.ENGLISH,"%6.2f%17d\n",in,amount[x]);
		}
		
	}
}
