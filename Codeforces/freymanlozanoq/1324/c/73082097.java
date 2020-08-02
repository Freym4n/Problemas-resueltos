import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static char arr[];
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk = new StringTokenizer(bf.readLine());
		int cases = Integer.parseInt(tk.nextToken()),cont,min,countR;
		Stack<Integer> s = new Stack<Integer>();
		for (int i = 0; i < cases; i++) {
			arr = bf.readLine().toCharArray();
			n = arr.length;
			cont = 1;
			min = 1;
			countR = 0;
			for (int j = 0; j < n; j++) {

				if (arr[j] == 'R') {
					cont = 1;
					countR ++;
				} else {
					cont ++;
					min = Math.max(min, cont);
				}
			}
			System.out.println(countR==0?n+1:min);
		}
	}
}
