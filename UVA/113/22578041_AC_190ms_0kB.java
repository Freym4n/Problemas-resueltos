import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		double n1, n2;
		while(bf.ready()) {
			n1 = Double.parseDouble(bf.readLine());
			n2 = Double.parseDouble(bf.readLine());
			System.out.printf("%.0f\n",Math.pow(n2, 1/n1));
		}
	}
}
