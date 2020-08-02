import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static ArrayList<Integer> original[];
	static ArrayList<Integer> nuevo[];
	static int A;
	static int B;
	static int[][] old;
	static int[][] neww;
	static int tempBFS[];
	static boolean v[];
	static int n;
	static boolean posible;

	static void BFS (int from, ArrayList<Integer>[] lst) {
		Queue<Integer> q = new LinkedList<Integer>();
		tempBFS = new int[n];
		v = new boolean[n];
		Arrays.fill(tempBFS, 1011);
		v[from] = true;
		tempBFS[from] = 0;
		int temp;
		q.add(from);
		while(!q.isEmpty()) {
			temp = q.poll();
			for (Integer i : lst[temp]) {
				if (!v[i]) {
					v[i] = true;
					tempBFS[i] = tempBFS[temp] + 1;
					q.add(i);
				}
			}
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk;
		int from;
		int elements;
		while((n = Integer.parseInt(bf.readLine())) != 0) {
			posible = true;
			original = new ArrayList[n];
			nuevo = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				original[i] = new ArrayList<Integer>();
				nuevo[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < n; i++) {
				tk = new StringTokenizer(bf.readLine());
				from = Integer.parseInt(tk.nextToken());
				elements = tk.countTokens();
				for (int j = 0; j < elements; j++) {
					original[from-1].add(Integer.parseInt(tk.nextToken())-1);
				}
			}
			old = new int[n][n];
			for (int i = 0; i < n; i++) {
				BFS(i,original);
				for (int j = 0; j < n; j++) {
					old[i][j] = tempBFS[j];
				}
			}
			for (int i = 0; i < n; i++) {
				tk = new StringTokenizer(bf.readLine());
				from = Integer.parseInt(tk.nextToken());
				elements = tk.countTokens();
				for (int j = 0; j < elements; j++) {
					nuevo[from-1].add(Integer.parseInt(tk.nextToken())-1);
				}
			}
			neww = new int[n][n];
			for (int i = 0; i < n; i++) {
				BFS(i,nuevo);
				for (int j = 0; j < n; j++) {
					neww[i][j] = tempBFS[j];
				}
			}
			tk = new StringTokenizer(bf.readLine());
			A = Integer.parseInt(tk.nextToken());
			B = Integer.parseInt(tk.nextToken());
			for (int i = 0; i < n && posible; i++) {
				for (int j = 0; j < n && posible; j++) {
					if (i == j) continue;
					if (neww[i][j]  > (old[i][j]*A + B)) {
						posible = false;
					}
				}
			}
			System.out.println(posible?"Yes":"No");

		}
	}
}