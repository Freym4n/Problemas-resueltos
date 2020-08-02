import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static boolean v[];
	static char[] s;
	static boolean pre[];
	static boolean suf[];
	
	
	static boolean is_palindrome(int l, int r) {
		while (l <= r) {
			if (s[l] == s[r]) {
				l++;
				r--;
			} else {
				return false;
			}
		} return true;
	}
	static int max_suffix(int l, int r) {
		while (l <= r) {
			if (is_palindrome(l, r)) {
				break;
			} l++;
		}
		if ( l > r) return 0;
		for (int i = l; i <= r; i++) {
			suf[i] = true;
		}
		return r - l + 1;
	}
	
	static int max_preffix(int l, int r) {
		while(l <= r) {
			if (is_palindrome(l, r) ) {
				break;
			} r--;
		}
		if (l > r) return 0;
		for(int i = l; i <= r; i++) {
			pre[i] = true;
		}
		return r - l + 1;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int l,r,tam, mp,ms;
		int n = Integer.parseInt(bf.readLine());
		for (int i = 0; i < n; i++) {
			s = bf.readLine().toCharArray();
			tam = s.length;
			v = new boolean[tam];
			pre = new boolean[tam];
			suf = new boolean[tam];
			l = 0;
			r = tam -1;
			while (l <= r) {
				if(s[l] == s[r]) {
					v[l] = true;
					v[r] = true;
				} else {
					mp = max_preffix(l, r);
					ms = max_suffix(l, r);
					if ( mp > ms) {
						for (int j = l; j <= r; j++) {
							v[j] = pre[j];
						}
					} else {
						for(int j = l; j <= r; j++) {
							v[j] = suf[j];
						}
					}
					break;
				}
				l++;
				r--;
			}
			for (int j = 0; j < tam; j++) {
				if (v[j]) System.out.print(s[j]);
			} System.out.println();
		}
		
	}
	
}
