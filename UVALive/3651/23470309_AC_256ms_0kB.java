import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n,c,k;
	static int times[];
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk;
		String linea;
		int min;
		while(!(linea = bf.readLine()).equals("0 0 0")) {
			tk = new StringTokenizer(linea);
			n = Integer.parseInt(tk.nextToken());
			c = Integer.parseInt(tk.nextToken());
			k = Integer.parseInt(tk.nextToken());
			times = new int[k+1];
			for (int i = 0; i < n; i++) {
				tk = new StringTokenizer(bf.readLine());
				for (int j = 0; j < c; j++) {
					times[Integer.parseInt(tk.nextToken())] ++;
				}
			}
			min=times[1];
			int m = 1;
			for (int i = 2; i < k+1; i++) {
				if (min > times[i]) {
					min = times[i];
					m = i;
				}
				
			}
			System.out.print(m);
			for (int i = 2; i < k +1; i++) {
				if (times[i] == min && i != m) {
					System.out.print(" "+i);
				} 
			} System.out.println();
		}
		
	}
}
