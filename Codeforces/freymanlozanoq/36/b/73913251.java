import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;

		public FastReader() throws FileNotFoundException  {
			bf = new BufferedReader(new FileReader("input.txt"));
			
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
	static int n,k;
	static boolean m[][];
	
	static boolean is_white(int x, int y) {
		int d = 1;
		int x1,y1;
		for (int i = 0; i < k; i++) {
			x1 = (x/d)%n;
			y1 = (y/d)%n;
			if (!m[x1][y1]) return false;
			d *= n;
		}
		return true;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		FastReader fr = new FastReader();
		PrintWriter pw = new PrintWriter("output.txt");
		n = fr.nextInt();
		k = fr.nextInt();
		char[] line;
		m = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			line = fr.next().toCharArray();
			for (int j = 0; j < n; j++) {
				if (line[j] == '.') m[i][j] = true; 
			}
		}
		StringBuilder linea;
		int max_n = (int)Math.pow(n, k);
		for (int i = 0; i <max_n; i++) {
			linea = new StringBuilder();
			for (int j = 0; j < max_n; j++) {
				if (is_white(i, j)) linea.append(".");
				else linea.append("*");
			}
			pw.print(linea.toString() + "\n");
			pw.flush();
		}
		
		
	}
}
