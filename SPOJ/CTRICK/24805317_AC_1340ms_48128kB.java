import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static int n;
	static int ans[];
	static int p[];

	static void make_set(int value) {
		p[value] = value;
	}

	static int find_set(int node) {
		if (node == p[node]) return node;
		return p[node]=find_set(p[node]);
	}

	static void union_set(int a, int b) {
		int pa = find_set(a);
		int pb = find_set(b);
		if (pa == pb)  return;
		p[pa] = pb;
	}

	static int find_next_free(int act,int d) {
		int i = act;
		while (d > 0) {
			i = find_set(i);
			d--;
			i++;
			if (i == n) i = find_set(0);
		}
		
		return find_set(i);
	}

	static void solve() {
		for (int i = 0; i < n; i++) make_set(i);
		int act = 0,index,tam = n;
		for (int i = 1; i <= n; i++) {
			index = find_next_free(act, i%tam);
			ans[index] = i;
			act = index;
			tam--;
			union_set(act, (act+1)%n);
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(bf.readLine());
		for (int i = 0; i < cases; i++) {
			n = Integer.parseInt(bf.readLine());
			ans = new int[n];
			p = new int[n];
			solve();
			for(int j = 0; j <  n; j++) {
				System.out.print(ans[j]);
				if (j < n - 1) System.out.print(" ");
			} System.out.println();
		}
	}
}
