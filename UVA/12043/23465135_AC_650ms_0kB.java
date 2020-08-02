import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[] prim;

	static void primos() {
		boolean[] v = new boolean[100001];
		v[1] = true;
		int cont = 0;
		prim = new int[9592];
		for (int i = 2; i < 100001; i++) {
			if (!v[i]) {
				prim[cont] = i;
				cont++;
				for (int j = i; j < 100001; j+=i) {
					v[j] = true;
				}
			}
		} 
	}
	
	static long sumatoria;
	static int divisores;
	
	static void solve(int x ) {
		int cont = 0;
		sumatoria = 1;
		divisores = 1;
		for(int i = 0; i < 9592 && prim[i]*prim[i] <= x ; i ++) {
			cont = 0;
			while (x % prim[i] == 0) {
				x /= prim[i];
				cont ++;
			}
			divisores *= cont + 1;
			sumatoria *= sumTemp(prim[i],cont);
		} if (x > 1) {
			divisores *= 2;
			sumatoria *= sumTemp(x,1); 
		}
	}

	static int sumTemp(int p, int cnt) {
		return (int) ((Math.pow(p, cnt+1)-1)/(p-1));
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		primos();
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int casos = Integer.parseInt(bf.readLine());
		StringTokenizer tk;
		int a,b,k,j; long sum,nDiv;
		for (int i = 0; i < casos; i++) {
			tk = new StringTokenizer(bf.readLine());
			a = Integer.parseInt(tk.nextToken());
			b = Integer.parseInt(tk.nextToken());
			k = Integer.parseInt(tk.nextToken());
			if (k == 0) {
				System.out.println("0 0");
				continue;
			}
			if (a % k != 0)
				j =   a +(k - a%k);
			else
				j = a;
			sum = 0;
			nDiv = 0;
			for (int l = j; l <= b; l+=k) {
				solve(l);
				sum += sumatoria;
				nDiv += divisores;
			} System.out.println(nDiv +  " " +sum);

		}

	}
}
