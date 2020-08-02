import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N = 1025;
	static int M[][] = new int[N][N];
	static int dp[][] = new int[N][N];
	static int d;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer  tk;
		int casos, nRats,i,j,size;
		casos = Integer.parseInt(bf.readLine());
		for (int k = 0; k < casos; k++) {
			d = Integer.parseInt(bf.readLine());
			nRats = Integer.parseInt(bf.readLine());
			M = new int [N][N];
			dp = new int[N][N];
			for (int k2 = 0; k2 < nRats; k2++) {
				tk = new StringTokenizer(bf.readLine());
				i = Integer.parseInt(tk.nextToken());
				j = Integer.parseInt(tk.nextToken());
				size = Integer.parseInt(tk.nextToken());
				M[i][j] = size;
			}
			for (int k2 = 1; k2 < N; k2++) {
				M[k2][0] = M[k2][0] + M[k2-1][0];
				M[0][k2] = M[0][k2] +  M[0][k2-1];
			}
			for (int x = 1; x < N; x++) 
				for (int y = 1; y < N; y++) 
					M[x][y] = M[x][y] +  M[x-1][y] + M[x][y-1] - M[x-1][y-1];
			

			for (int x = 0; x < N; x++) {
				if (x < 2*d+1) {
					dp[x][0] = M[x][0];
					dp[0][x] = M[0][x];
				} else {
					dp[x][0] = M[x][0] -  M[x-2*d-1][0];
					dp[0][x] = M[0][x] - M[0][x-2*d-1];
				}
			}
			for (int x = 1; x < N; x++) {
				for (int y = 1; y < N; y++) {
					if (x < 2*d+1 && y < 2*d+1) {
						dp[x][y] = M[x][y];
					} else if (x < 2*d+1) {
						dp[x][y] = M[x][y] - M[x][y-2*d-1];
					} else if (y < 2*d+1) {
						dp[x][y] = M[x][y] -  M[x-2*d-1][y];
					} else {
						dp[x][y] = M[x][y] - M[x-2*d-1][y] - M[x][y-2*d-1] + M[x-2*d-1][y-2*d-1];
					}
				}
			}
			i = 0; j = 0; int maximo = 0;
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < N; y++) {
					if (dp[x][y] > maximo) {
						maximo = dp[x][y];
						i = x;
						j = y;
					}
				}
			} System.out.println(Math.max(0, i-d) + " "+ Math.max(0, j-d) + " " +maximo);
			
		}
		
	}
}
