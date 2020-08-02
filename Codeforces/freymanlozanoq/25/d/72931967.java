import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static class Par {
		int a,b;

		public Par(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}

		@Override
		public String toString() {
			return (a+1) + " " + (b+1);
		}

	}
	static int parent[];
	static int n;
	static int m;
	static int cont;
	static Par p[];
	static Queue<Par> q = new LinkedList<Par>();
	static Queue<Par> q2 = new LinkedList<Par>();
	static boolean ready[];
	
	static void solve() {
		cont = n;
		for (int i = 0; i < n; i++) 
			make_set(i);
		for (int i = 0; i < m; i++) {
			if (union_set(p[i])) cont --;
			else q.add(p[i]);
		}
		if (cont == 0) return;
		int a = find_set(0),b;
		for (int i = 1; i < n && cont >= 1; i++) {
			b = find_set(i);
			if ( a == b || (ready[a] && ready[b])) continue;
			ready[a] = ready[b] = true;
			q2.add(new Par(a,b));
			a = b;
			cont --;
		}
	}


	static void make_set(int value) {
		parent[value] = value;
	}

	static int find_set(int a) {
		if (a == parent[a]) return a;
		return parent[a] = find_set(parent[a]);
	}

	static boolean union_set(Par p) {
		int a = find_set(p.a);
		int b = find_set(p.b);
		if (a == b) return false;
		parent[b] = a;
		return true;
	}


	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk = new StringTokenizer(bf.readLine());
		int a,b;
		n = Integer.parseInt(tk.nextToken());
		m = n  - 1;
		parent = new int[n];
		ready = new boolean [n];
		p = new Par[m];
		for (int i = 0; i < m; i++) {
			tk = new StringTokenizer(bf.readLine());
			a = Integer.parseInt(tk.nextToken())-1;
			b = Integer.parseInt(tk.nextToken())-1;
			p[i] = new Par(a,b);
		}
		solve();
		int tam = q.size();
		System.out.println(tam);
		for (int i = 0; i < tam; i++) {
			System.out.println(q.poll().toString() + " " + q2.poll().toString());
		}
	
		
	}
}
