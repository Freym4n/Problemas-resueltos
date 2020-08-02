import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
class Edge {
	int a,b,cost;

	public Edge(int a, int b) {
		super();
		this.a = a;
		this.b = b;
		this.cost = 0;
	}


}
public class Main {

	static Edge e[];
	static ArrayList<Edge> lst = new ArrayList<Edge>();
	static int energy[];
	static boolean v[];
	static int d[];
	static int n;
	static int m;
	static final int inf = Integer.MIN_VALUE;
	static final int infp = Integer.MAX_VALUE - 100000;
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int to,ed,caso = 1;
		while((n = sc.nextInt()) > 0) {
			m = 0;
			lst.clear();
			energy = new int[n];
			v = new boolean[n];
			for (int i = 0; i < n; i++) {
				energy[i] = sc.nextInt();
				ed = sc.nextInt();
				m += ed;
				for (int j = 0; j < ed; j++) {
					to = sc.nextInt()-1;
					lst.add(new Edge(i,to));
				}
			}
			e = new Edge[m];
			for (int i = 0; i < m; i++) {
				e[i] = lst.get(i);
				e[i].cost = energy[e[i].b];
			}
			System.out.println((solve()?"winnable":"hopeless"));
			caso++;
		}
	}

	static boolean solve() {
		d = new int[n];
		Arrays.fill(d, inf);
		d[0] = 100;
		v[0] = true;
		recorrer();
		if (d[n-1] > 0 && v[n-1]) return true;
		int temp = d[n-1];
		encontrarCiclos();
		if (temp < d[n-1] && v[n-1]) return true;
		return false;
	}


	static void recorrer() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++) {
				if (d[e[j].a] > inf) {
					if (d[e[j].a] + e[j].cost >= d[e[j].b] && (v[e[j].a] || !v[e[j].b])){
						d[e[j].b] = d[e[j].a] + e[j].cost;
						if(v[e[j].a] && d[e[j].b] > 0) v[e[j].b] = true;
						else v[e[j].b] = false;
					}
				}

			}
		}
	}

	static void encontrarCiclos() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++) {
				if (d[e[j].a] > inf) {
					if (d[e[j].a] + e[j].cost > d[e[j].b] && (v[e[j].a] || !v[e[j].b])){
						d[e[j].b] = infp;
						if(v[e[j].a] && d[e[j].b] > 0) v[e[j].b] = true;
						else v[e[j].b] = false;
					}
				}

			}
		}
	}
}
