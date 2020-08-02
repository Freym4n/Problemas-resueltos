import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
	
	
	public static void main(String[] args) throws FileNotFoundException {
		FastReader fr =new FastReader();
		BigInteger a;
		int n,d;
		n = fr.nextInt();
		d = fr.nextInt();
		while (n != 0) {
			a = new BigInteger(Integer.toString(n));
			a = a.pow(d);
			System.out.println(a.toString());
			n = fr.nextInt();
			d = fr.nextInt();
		}
		
	}
	
	
	
	
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
}
