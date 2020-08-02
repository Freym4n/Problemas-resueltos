import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {


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


	static int n;

	static boolean[] v;

	static Queue<Integer> lst[];

	public static void main(String[] args) {
		FastReader fr = new FastReader();
		int t = fr.nextInt();
		int k;
		int temp,cont = 0;
		int to=0,from=0;
		for (int c = 0; c < t; c++) {
			cont = 0;
			n = fr.nextInt();
			v = new boolean[n];
			lst = new Queue[n];
			for(int i = 0; i < n; i++)
				lst[i] = new LinkedList<Integer>();
			for (int i = 0; i < n; i++) {
				k = fr.nextInt();
				for (int j = 0; j < k; j++) {
					lst[i].add(fr.nextInt()-1);
				}
				for (int j = 0; j < k; j++) {
					temp = lst[i].poll();
					if (v[temp]) continue;
					else {
						v[temp] = true;
						lst[i].add(temp);
						cont++;
						break;
					}
				}
			}
			if (cont == n) {
				System.out.println("OPTIMAL");
			} else {
				System.out.println("IMPROVE");
				for (int i = 0; i < n; i++) {
					if (lst[i].size() == 0) {
						from = i+1;
					}
					if (!v[i]) {
						to = i + 1;
					}
				}
				System.out.println(from + " " +to);
			}
		}

	}

}
























