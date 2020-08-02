import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
		
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		BigInteger a;
		int n,d;
		n = sc.nextInt();
		d = sc.nextInt();
		while (n != 0) {
			a = new BigInteger(Integer.toString(n));
			a = a.pow(d);
			System.out.println(a.toString());
			n = sc.nextInt();
			d = sc.nextInt();
		}	
	}
}
