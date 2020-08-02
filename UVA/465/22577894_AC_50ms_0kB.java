import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) throws IOException {
		//
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader bf = new BufferedReader(new FileReader("p.txt"));
		BigInteger n1, n2;
		String operador;
		String linea[],line;
		while(bf.ready()) {
			line = bf.readLine();
			linea = line.split(" ");
			n1 = new BigInteger(linea[0]);
			operador = linea[1];
			n2 = new BigInteger(linea[2]); 
			System.out.println(line);
			if (n1.compareTo(new BigInteger(Integer.toString(Integer.MAX_VALUE))) > 0) {
				System.out.println("first number too big");
			}
			if (n2.compareTo(new BigInteger(Integer.toString(Integer.MAX_VALUE))) > 0) {
				System.out.println("second number too big");
			}
			if (operador.equals("+")) {
				if (n1.add(n2).compareTo(new BigInteger(Integer.toString(Integer.MAX_VALUE))) > 0) {
					System.out.println("result too big");
				}
			} else {
				if (n1.multiply(n2).compareTo(new BigInteger(Integer.toString(Integer.MAX_VALUE))) > 0) {
					System.out.println("result too big");
				}
			}
		}
	}
}
