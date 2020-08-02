import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {


	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk = new StringTokenizer(bf.readLine());
		int cases = Integer.parseInt(tk.nextToken()),n, a[];
		boolean isPosible = true;
		for (int i = 0; i < cases; i++) {
			isPosible = true;
			tk = new StringTokenizer(bf.readLine());
			n = Integer.parseInt(tk.nextToken());
			a = new int[n];
			tk = new StringTokenizer(bf.readLine());
			for (int j = 0; j < n; j++) {
				a[j] = Integer.parseInt(tk.nextToken());
				if (j > 0 && (a[j] - a[j-1])%2 != 0 ) isPosible = false;
			}
			System.out.println(isPosible?"YES":"NO");
		}
	}
}

