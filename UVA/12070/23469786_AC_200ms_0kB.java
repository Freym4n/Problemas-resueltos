import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


class Par{
	int i,j;

	public Par(int i, int j) {
		super();
		this.i = i;
		this.j = j;
	}
}

class Item implements Comparable<Item>{
	Par v; int d, t;

	public Item(int i, int j, int d,int t) {
		super();
		this.v = new Par(i,j);
		this.d = d;
		this.t = t;
	}

	@Override
	public int compareTo(Item q) {
		return this.d - q.d;
	}


}
public class Main {

	static int l = 260000;
	static int m[][];
	static int n;
	static int t;
	static int f;

	static int dif[][] = {{1,0},{0,1},{-1,0},{0,-1}};

	static int dp[][][];
	static int result[][];
	static void solve(int i, int j, int v) {


	}
	static int[][] dijkstra(int x, int y) {
		int i,j, it,jt;
		boolean v[][][] = new boolean[n][n][t+1];
		int dist[][][] = new int[n][n][t+1];
		PriorityQueue<Item>  q = new PriorityQueue<Item>();
		for (int k = 0; k < n; k++) 
			for (int k2 = 0; k2 < n; k2++) 
				for(int k3 = 0; k3 < t+1; k3++)
					dist[k][k2][k3] = l;
		dist[x][y][0] = 0;
		q.offer(new Item(x,y,0,0));
		Item temp;
		while(!q.isEmpty()) {
			temp = q.poll();
			i = temp.v.i;
			j = temp.v.j;
			if (!v[i][j][temp.t]) {
				v[i][j][temp.t] = true;
				for (int k = 0; k < 4; k++) {
					it =i + dif[k][0];
					jt =j + dif[k][1];
					if (sePuede(new Par(x,y), new Par(it,jt)) && temp.t < t) {
						if (dist[it][jt][temp.t +1]  > dist[i][j][temp.t] +  m[i][j]) {
							dist[it][jt][temp.t +1] = dist[i][j][temp.t] + m[i][j];
							q.offer(new Item(it,jt,dist[it][jt][temp.t+1],temp.t+1));
						}
					}
				}	
			} 
		} 
		for (int k = 0; k < n; k++) {
			for (int k2 = 0; k2 < n; k2++) {
				for (int l = 0; l < t+1; l++) {
					dist[k][k2][0] = Math.min(dist[k][k2][l], dist[k][k2][0]);
				}
			}
		}
		int result[][] = new int[n][n];
		for (int k = 0; k < n; k++) {
			for (int k2 = 0; k2 < n; k2++) {
				result[k][k2] = dist[k][k2][0];
			}
		} return result;
 	}

	static boolean sePuede(Par from,Par p) {
		return p.i < n && p.i >= 0 && p.j < n && p.j >= 0 && (Math.abs(from.j-p.j) + Math.abs(from.i - p.i) <= t);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String linea;
		StringTokenizer tk;
		int x,y;
		int caso = 1;
		while(!(linea = bf.readLine()).equals("0 0 0")) {
			tk = new StringTokenizer(linea);
			n = Integer.parseInt(tk.nextToken());
			f = Integer.parseInt(tk.nextToken());
			t = Integer.parseInt(tk.nextToken());
			m = new int [n][n];
			for (int i = 0; i < n; i++) {
				tk = new StringTokenizer(bf.readLine());
				for (int j = 0; j < n; j++) {
					m[i][j] = Integer.parseInt(tk.nextToken());
				}
			}
			int result[][][] = new int [f][n][n];
			int sum [][] = new int[n][n];
			for (int i = 0; i < f; i++) {
				tk = new StringTokenizer(bf.readLine());
				x = Integer.parseInt(tk.nextToken());
				y = Integer.parseInt(tk.nextToken());
				result[i] = dijkstra(x, y);
			}
			int costo = l;
			x = 0; y = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int j2 = 0; j2 < f; j2++) {
						sum[i][j] += result[j2][i][j];
					}
					if (sum[i][j] < costo) {
						costo = sum[i][j];
						x = i;
						y = j;
					}
				}
			}
			System.out.println("Case #" + caso+ ": " +(costo >= l?"Impossible.":"Selected city ("+x+","+y+") with minimum cost "+costo+"."));
			caso++;
		}


	}
}
