import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static int a[];
	static boolean visi[];
	static final int tam = 5000;
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk = new StringTokenizer(bf.readLine());
		int cases = Integer.parseInt(tk.nextToken());
		boolean isPosible = true;
		Stack<Integer> s = new Stack<Integer>();
		for (int i = 0; i < cases; i++) {
			isPosible = false;
			tk = new StringTokenizer(bf.readLine());
			n = Integer.parseInt(tk.nextToken());
			a = new int[n];
			tk = new StringTokenizer(bf.readLine());
			for (int j = 0; j < n; j++) {
				a[j] = Integer.parseInt(tk.nextToken());
			}

			//encontrar lenght 3
			for (int j = 0; j < n-2; j++) {
				for (int j2 = j+2; j2 < n; j2++) {
					if (a[j2] == a[j]) isPosible = true;
				}
			}
			boolean p = false;
			for (int j = 0; j < n-3; j++) {
				visi = new boolean [tam];
				for (int j2 = j+3; j2 < n; j2++) {
					if (a[j2] == a[j] && p) {
						isPosible = true;
					} else {
						if (visi[j2]) p = true;
						else visi[j2] = true;
					}
				}
			}

			System.out.println(isPosible?"YES":"NO");
		}
	}
}
