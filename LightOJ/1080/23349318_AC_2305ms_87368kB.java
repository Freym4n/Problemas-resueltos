import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int bit[];
	static int lista[];
	static int n;

	static void add(int index, int val) {
		for (; index < n; index = (index|(index+1))) 
			bit[index] += val;
	}

	static void range_add(int l, int r, int val) {
		add(l,val);
		add(r+1,-val);
	}

	static int point_query(int index) {
		int result = 0;
		for(; index >= 0; index  = (index&(index+1))-1)
			result += bit[index];
		return result;
	}


	static void createBIT() {
		for (int i = 0; i < n; i++) {
			range_add(i,i, lista[i]);
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk;
		int casos = Integer.parseInt(bf.readLine()),nQ,index,l,r;
		char type;
		String linea[];
		for (int i = 0; i < casos; i++) {
			System.out.println("Case "+(i+1)+":");
			linea = bf.readLine().split("");
			n = linea.length;
			lista = new int [n];
			bit = new int [n];
			for (int j = 0; j < n; j++) {
				lista[j] = Integer.parseInt(linea[j]);
			}
			createBIT();
			nQ = Integer.parseInt(bf.readLine());
			for (int j = 0; j < nQ; j++) {
				
				tk = new StringTokenizer(bf.readLine());
				type = tk.nextToken().charAt(0);
				if (type == 'Q') {
					index = Integer.parseInt(tk.nextToken())-1;
					System.out.println(point_query(index)%2);
				} else {
					l = Integer.parseInt(tk.nextToken())-1;
					r = Integer.parseInt(tk.nextToken())-1;
					range_add(l, r, 1);
				}
			}
		}
	}

}
