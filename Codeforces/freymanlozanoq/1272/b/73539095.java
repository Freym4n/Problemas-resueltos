import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class J {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(bf.readLine());
		char in[],t;
		int l[],max;
		int numL,n;
		StringBuilder result;
		for (int i = 0; i < cases; i++) {
			l = new int[4];
			max = 0;
			result = new StringBuilder("");
			numL = 0;
			in = bf.readLine().toCharArray();
			n = in.length;
			for (int j = 0; j < n; j++) {
				t = in[j];
				if (t == 'L') {
					l[0] ++;
					if (l[0] == 1) numL++;
				} else if(t == 'R') {
					l[1] ++;
					if (l[1] == 1) numL ++;
				} else if (t == 'D') {
					l[2] ++;
					if (l[2] == 1) numL ++;
				} else {
					l[3] ++;
					if (l[3] == 1)  numL ++;
				}
			}

			if (numL == 2) {
				if (l[0] != 0 && l[1] != 0) {
					result.append("LR");
					max = 2;
				}
				else if (l[2] != 0 && l[3] != 0) {
					result.append("DU");
					max = 2;
				}
			} else if (numL == 3) {
				if (l[0] != 0 && l[1] != 0) result.append("LR"); 
				else result.append("DU");
				max = 2;
			} else if (numL == 4){
				l[0] = l[1] = Math.min(l[0], l[1]);
				l[2] = l[3] = Math.min(l[2], l[3]);
				for(int j = 0; j < l[0] ; j++) result.append("L");
				for(int j = 0; j < l[2] ; j++) result.append("D");
				for(int j = 0; j < l[1] ; j++) result.append("R");
				for(int j = 0; j < l[3] ; j++) result.append("U");
				max = l[0]*2 + l[2]*2;
 			}
			System.out.println(max);
			System.out.println(result);
		}
	}
}
