import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static class FastReader {
		BufferedReader bf;
		StringTokenizer st;
		public FastReader()  {
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
		Main m = new Main();
		m.solve(fr);
		fr.close();
	}

	class Pair implements Comparable<Pair>{
		int x; int y;
		@Override
		public int compareTo(Pair arg0) {
			if (this.x == arg0.x)
				return (this.y - arg0.y);
			return (this.x - arg0.x);
		}
		public Pair(int id, int w) {
			super();
			this.x = id;
			this.y = w;
		}
		@Override
		public String toString() {
			return "Pair [x=" + x + ", y=" + y + "]";
		}

	}

	int search(long arr[], long x) {
		int r = arr.length-1, l = 0, mid = r/2;
		int best_option = -1;
		while(l <= r) {
			mid = l + (r-l)/2;
			if (arr[mid] > x) {
				r = mid - 1;
			} else {
				best_option= mid;
				l = mid + 1;
			}
		}
		return best_option;
	}

	int n;
	long p;
	long a[];
	long even[];
	long odd[];
	
	public void solve(FastReader fr) throws IOException {
		int t = fr.nextInt();
		while(t-->0) {
			n  = fr.nextInt();
			p = fr.nextLong();
			fr.next();
			a = new long[n];
			even = new long[n];
			odd = new long[n];
			for(int i = 0; i <n; i++) {
				a[i] = fr.nextLong();
			}
			Arrays.sort(a);
			even[0] = a[0];
			odd[0] = a[0];
			for(int i = 1; i < n; i++) {
				even[i] = even[i-1] + a[i];
				if ((i&1)== 0) even[i] -= a[i-1];
			}
			for(int i = 1; i < n; i++) {
				odd[i] = odd[i-1] + a[i];
				if ((i&1)==1) odd[i] -= a[i-1];
			}
			int ans = search(even, p);
			ans = Math.max(search(odd, p), ans);
			System.out.println(ans+1);
		}
	}





}
