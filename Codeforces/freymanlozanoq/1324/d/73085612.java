import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {



	static int n;
	static int a[];
	static int b[];
	static Topic t[];


	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk = new StringTokenizer(bf.readLine());
		n = Integer.parseInt(tk.nextToken());
		long temp, cont;
		a = new int[n];
		b = new int[n];
		t = new Topic[n];
		tk = new StringTokenizer(bf.readLine());
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(tk.nextToken());
		}
		tk =new StringTokenizer(bf.readLine());
		for (int i = 0; i < n; i++) {
			b[i] = Integer.parseInt(tk.nextToken());
		}
		for (int i = 0; i < n; i++) {
			t[i] = new Topic(a[i],b[i]);
		}
		Arrays.parallelSort(t);
		cont = 0;
		for (int i = 0; i < n-1; i++) {
			temp = search(i + 1, t[i].dif);
			cont += (n - temp);
		}
		System.out.println(cont);
		
	}
	
	
	static long search(int l,int x) {
		int r = n-1, mid = l + (r - l)/2;
		while (l <= r) {
			if (t[mid].dif  + x > 0) {
				if (mid == 0 || t[mid-1].dif + x <= 0) {
					return mid;
				} else {
					r = mid - 1;
				}
			} else {
				l = mid  + 1;
			}
			mid = l + (r - l)/2;
		}
		return (long) mid;
	}
}



class Topic implements Comparable<Topic>{
	int a,b, dif;

	public Topic(int a, int b) {
		super();
		this.a = a;
		this.b = b;
		this.dif = a - b;
	}

	@Override
	public String toString() {
		return "dif=" + dif ;
	}

	@Override
	public int compareTo(Topic arg0) {
		return this.dif - arg0.dif;
	}


}