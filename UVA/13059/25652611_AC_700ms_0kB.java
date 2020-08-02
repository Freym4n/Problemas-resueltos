import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;

		public FastReader() throws FileNotFoundException  {
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
		BigInteger n;
		while(fr.ready()) {
			n = new BigInteger(fr.next());
			n = n.subtract(BigInteger.ONE);
			System.out.println(n);
		}
		
	}
}
