import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	static int solve(int n, int k) {
		int front;
		int t_f = ((k&1) > 0?k-1:k);
		front = t_f/2;
		int back;
		if ((n&1) == 0) n++;
		int t_b = ((k&1) == 0?k+1:k);
		back = (n-t_b)/2;
		return Math.min(back, front);
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bf.readLine());
		int k = Integer.parseInt(bf.readLine());
		System.out.println(solve(n,k));
		
		
	}
}
