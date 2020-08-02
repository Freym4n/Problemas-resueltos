import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main {
	
	static ArrayList<Integer> lst;
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader bf = new BufferedReader(new FileReader("p.txt"));
		
		int casos = Integer.parseInt(bf.readLine()), numero;
		for (int i = 0; i < casos; i++) {
			lst = new ArrayList<Integer>();
			numero = Integer.parseInt(bf.readLine());
			System.out.println("Case #"+(i+1)+": "+numero+(solve(numero)?" is a Happy number.":" is an Unhappy number."));
		}
		

	}
	
	
	public static boolean solve( int n) {
		if (n == 1)
			return true;
		if (lst.contains(n)) 
			return false;
		int b = 0;
		lst.add(n);
		String a[] = Integer.toString(n).split("");
		for (int i = 0; i < a.length; i++) {
			b += Math.pow(Integer.parseInt(a[i]),2);
		}
		
		return solve(b);
		
	}
}
