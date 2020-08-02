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
	
	
	public static void main(String[] args) {
		FastReader fr = new FastReader();
		int t = fr.nextInt();
		StringBuilder result;
		int n,sum;
		for (int i = 0; i < t; i++) {
			sum = 0;
			result = new StringBuilder();
			n = fr.nextInt();
			if (n == 1) {
				result.append("-1");
			} else {
				if ( ((n-1)*2) % 3 == 0) {
					for(int j = 0; j < n-2; j ++) {
						result.append("2");
					}
					result.append("33");
				} else {
					for (int j = 0; j < n -1; j++) {
						result.append("2");
					} result.append("3");
				}
			}
			System.out.println(result.toString());
		}
		
		
	}
	
}
























