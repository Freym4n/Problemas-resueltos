import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class R {

	public static void main(String[] args) {
		FastReader fr = new FastReader();
		long a[] = new long[3];
		a[0] = fr.nextLong();
		a[1] = fr.nextLong();
		a[2] = fr.nextLong();
		Arrays.parallelSort(a);
		long result = 0;
		if (a[0] == 0 && a[1] == 1) {
			System.out.println(a[2]);
		} else if (a[0] == a[1]) {
			System.out.println(a[0]);
		} else if (a[2] == a[1]) {
			System.out.println(a[2]);
		} else if ((a[1] - a[0]) % 2 == 1) {
			result += a[2] - a[1];
			result += a[1];
			System.out.println(result);
		} else {
			result += (a[1]-a[0])/2;
			result += (a[1]+a[0])/2;
			System.out.println(result);
		}
	}


	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;

		public FastReader()  {
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
