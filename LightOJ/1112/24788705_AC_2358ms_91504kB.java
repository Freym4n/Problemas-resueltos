import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;

public class Main {
	
	static int n;
	static int bit[];
	static int a[];
	
	static void add(int index, int value) {
		for(int i = index; i < n; i = (i|(i+1))) {
			bit[i] += value;
		}
	}
	
	static void create() {
		for (int i = 0; i < n; i++) {
			add(i, a[i]);
		}
	}
	
	static int query(int index) {
		int result = 0;
		for(int i = index; i >= 0; i = (i&(i+1))-1) {
			result += bit[i];
		}
		return result;
	}
	
	static int range_query(int i, int j) {
		return query(j) - query(i-1);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk;
		int q, i,j,v; char type;
		int cases = Integer.parseInt(bf.readLine());
		for (int k = 0; k < cases; k++) {
			System.out.println("Case "+(k+1)+":");
			tk = new StringTokenizer(bf.readLine());
			n = Integer.parseInt(tk.nextToken());
			q = Integer.parseInt(tk.nextToken());
			a = new int[n];
			bit = new int[n];
			tk = new StringTokenizer(bf.readLine());
			for (int k2 = 0; k2 < n; k2++) {
				a[k2] = Integer.parseInt(tk.nextToken());
			}
			create();
			for (int k2 = 0; k2 < q; k2++) {
				tk = new StringTokenizer(bf.readLine());
				type = tk.nextToken().charAt(0);
				if (type == '1') {
					i = Integer.parseInt(tk.nextToken());
					System.out.println(a[i]);
					add(i, -a[i]);
					a[i] = 0;
				} else if (type == '2') {
					i = Integer.parseInt(tk.nextToken());
					v = Integer.parseInt(tk.nextToken());
					add(i, v);
					a[i] += v;
				} else {
					i = Integer.parseInt(tk.nextToken());
					j = Integer.parseInt(tk.nextToken());
					System.out.println(range_query(i, j));
				}
			}
		}
		
	}
}
