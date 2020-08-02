import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static int n,m;
	static int in[][];
	static int dist[][];

	static boolean is_ok(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}

	static int solve() {
		int dx[] = {-1,0,1,0};
		int dy[] = {0,1,0,-1};
		dist = new int[n][m];
		for(int i = 0; i < n; i++) 
			Arrays.fill(dist[i], -1);
		dist[0][0] = in[0][0];
		PriorityQueue<Item> q = new PriorityQueue<Item>();
		q.offer(new Item(0,0,dist[0][0]));
		Item t;
		int x,y;
		while (!q.isEmpty()) {
			t = q.poll();
			for (int i = 0; i < 4; i++) {
				x = t.x + dx[i];
				y = t.y + dy[i];
				if (!is_ok(x,y)) continue;
				if (dist[x][y] == -1) {
					dist[x][y] = t.w + in[x][y];
					q.offer(new Item(x,y,dist[x][y]));
				}

			}

		}
		return dist[n-1][m-1];
	}
	
	public static void main(String[] args) {
		FastReader fr = new FastReader();
		int t;
		t = fr.nextInt();
		for (int i = 0; i < t; i++) {
			n = fr.nextInt();
			m = fr.nextInt();
			in = new int[n][m];
			for(int j = 0; j < n; j++) 
				for(int k = 0; k < m; k++) 
					in[j][k] = fr.nextInt();
			System.out.println(solve());	
			
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

class Item implements Comparable<Item>{
	int x,y,w;
	@Override
	public int compareTo(Item arg0) {
		return this.w - arg0.w;
	}
	public Item(int x, int y, int w) {
		super();
		this.x = x;
		this.y = y;
		this.w = w;
	}	

}