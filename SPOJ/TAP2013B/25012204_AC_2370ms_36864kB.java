import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
		
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n;
		n = sc.nextInt();
		double a[] = new double[n];
		
		
		double sum = 0;
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextDouble();
			sum += a[i];
		}
		boolean p = false;
		for(int i = 0; i <n; i++) {
			if (a[i] / sum >= 0.45) {
				p = true;
				break;
			}
		}
		boolean temp = false;
		for(int i = 0; i < n && !p; i++) {
			if (a[i]/sum  < 0.4) continue;
			temp = true;
			for(int j = 0; j < n && temp; j++) {
				if (i == j) continue;
				if (a[i] < (a[j] + sum/10)) temp = false;
			}
			if (temp) break;
		}
		p = (p | temp);
		System.out.println(p?"1":"2");
	}
}
