import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

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
	
	static class elephant implements Comparable<elephant>{
		int iq,  w, id;


		public elephant(int iq, int w, int id) {
			super();
			this.iq = iq;
			this.w = w;
			this.id = id;
		}


		@Override
		public int compareTo(elephant arg0) {
			if (this.iq == arg0.iq)
				return this.w - arg0.w;
			else return this.iq - arg0.iq;
		}
	}
	
	static int bin_search(int x, int arr[]) {
		int l = 0, r = arr.length -1 , mid = r / 2;
		while (l <= r) {
			if (arr[mid] == x) {
				return mid;
			} else if (arr[mid] > x) {
				l = mid + 1;
			} else  {
				r = mid - 1;
			}
			mid = l + (r - l)/2;
		} return mid;
	}
	
	static void find_id(int init) {
		int max_m = m -1;
		for (int i = n -1; i >= 0; i--) {
			for (int j = max_m; j >= 0; j--) {
				if (id[i][j] == 0) continue;
				if (dp[i][j] != init) continue;
				System.out.println(id[i][j]);
				i++;
				max_m = j - 1;
				init--;
				break;
			}
		}
	}
	
	static int solve() {
		for (int i = 1; i < n; i++) 
			for (int j = 1; j < m; j++) 
				dp[i][j] = Math.max(dp[i-1][j-1] + dp[i][j], Math.max(dp[i-1][j], dp[i][j-1]));
		return (dp[n-1][m-1]);
		
	}
	
	static int iq[],w[],dp[][],n,m, id[][];
	static elephant[] e;
	static Set<Integer> set_iq = new TreeSet<Integer>();
	static Set<Integer> set_w = new TreeSet<Integer>();;
	static Set<elephant> lst_e =new TreeSet<elephant>();
	
	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader();
		int iqt,wt,idt = 0;
		while(fr.ready()) {
			idt++;
			wt = fr.nextInt();
			iqt = fr.nextInt();
			set_iq.add(iqt);
			set_w.add(wt);
			lst_e.add(new elephant(iqt, wt,idt));
		}
		n = set_iq.size();
		m = set_w.size();
		dp = new int[n][m];
		id = new int[n][m];
		iq = new int[n];
		w = new int[m];
		int cont = 0;
		for (Integer i : set_iq) {
			iq[cont] = i;
			cont ++;
		}
		cont = m-1;
		for (Integer i : set_w) {
			w[cont] = i;
			cont --;
		}
		int x,y;
		for (elephant e : lst_e) {
			y = bin_search(e.w, w);
			x = Arrays.binarySearch(iq, e.iq);
			idt = e.id;
			dp[x][y] = 1;
			id[x][y] = idt;
		}
		x = solve();
		System.out.println(x);
		find_id(x);
	}
}


