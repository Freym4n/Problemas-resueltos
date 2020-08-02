import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static String result[];
	static int n;
	static String l[];
	static boolean v[][];
	static int disp[];
	static final int MAX = 1024;
	
	static void gen_mask(int l,int r, char[] a ) {
		int m = 1023;
		for (int i = 0; i < a.length-1; i++) {
			m = (m ^ (1 << (a[i]-48)));
		}
		for(int i = l; i < l + r; i++) {
			disp[i] = m;
		}
	}

	static boolean solve(int index, int mask) {
		if (index == n) return true;
		if (v[index][mask]) return false;
		boolean x = false;
		int d = 1;
		int mask_act =( mask  | disp[index]);
		for (int i = 0; i < 10; i++) {
			if ((d&mask_act) == 0) {
				x = solve(index+1, (mask|d));
				if (x) {
					result[i] = l[index];
					return true;
				}
			}
			d <<= 1;
		}
		v[index][mask]= true;
		return false;
	}


	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader bf = new BufferedReader(new  FileReader("input.txt"));
		StringTokenizer tk;
		String l_n;
		char[] to;
		String letra;
		boolean r;
		int num,cont;
		while(bf.ready()) {
			l = new String[10];
			disp = new int[10];
			cont = 0;
			while (bf.ready() && (tk = new StringTokenizer(bf.readLine())).countTokens() > 0 ) {
				l_n = (tk.nextToken());
				to = tk.nextToken().toCharArray();
				num = l_n.charAt(1)-48;
				letra = l_n.charAt(0)+"";
				for(int i = cont; i < cont + num && cont + num <= 10; i++) {
					l[i] = letra;
				}
				if (cont + num <= 10)
					gen_mask(cont,num,to);
				cont += num;
				n = cont;
			}
			if (n > 10) {
				System.out.println("!");
			} else {
				result = new String[10];
				v = new boolean[n][MAX];
				Arrays.fill(result, "_");
				r = solve(0,0);
				if (r) {
					for (int i = 0; i < 10; i++) {
						System.out.print(result[i]);
					} System.out.println();
				} else {
					System.out.println("!");
				}
			}
		}
	}
}
