import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class K {
	static int[] list;
	static int n;
	static int right, left, middle;
	static int binarySearch(int x) {
		int l = 0, r = n-1 , mid = r >> 1;
		while(l <= r) {
			if (list[mid] == x) {
				return mid;
			} else if(list[mid] > x) {
				r =  mid - 1;
			} else {
				l = mid + 1;
			}
			mid = (l + r)/2;
		} return -1;
	}


	static int solve() {
		int max = 1, index,mid,l;
		for (int i = 0; i < n; i++) {
			l = list[i];
			for (int r = 1;l + r <= list[n-1]; r*=2) {
				index = binarySearch(l + r);
				if (index < 0) continue;
				if (r == 1 || max < 2) {
					max = 2;
					right= l + r;
					left = l;
					if (r == 1 || ((l + r)&1) == 1)continue;
				}
				mid = binarySearch((2*l + r)/2);
				if (mid < 0) continue;
				right = l +  r;
				left = l;
				middle = list[mid];
				max = 3;
				return max;
				
			}
		} return max;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk = new StringTokenizer(bf.readLine());
		n = Integer.parseInt(tk.nextToken());
		list = new int[n];
		tk = new StringTokenizer(bf.readLine());
		for (int i = 0; i < n; i++) {
			list[i] = Integer.parseInt(tk.nextToken());
		}
		Arrays.parallelSort(list);
		int result = solve();
		System.out.println(result);
		if (result == 1 ) System.out.println(list[0]);
		else if (result == 2) System.out.println(right + " " + left);
		else System.out.println(right + " " + left + " " + middle);
	}
}
