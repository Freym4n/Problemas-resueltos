import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bf.readLine()),x;
		for (int i = 0; i < n; i++) {
			x = Integer.parseInt(bf.readLine());
			System.out.println("1 "+(x-1));
		}
	}
}
