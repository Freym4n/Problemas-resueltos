import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
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

	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader();
		BigInteger a;
		BigInteger m;
		int x;
		String linea;
		while (fr.ready()) {
			linea = fr.next();
			System.out.println(linea+"!");
			x = Integer.parseInt(linea);
			a = new BigInteger("1");
			m = new BigInteger("2");
			for(int i = 2; i <= x; i++) {
				a = a.multiply(m);
				m = m.add(BigInteger.ONE);
			}
			System.out.println(a.toString());
		}
		
		
		
	}
}