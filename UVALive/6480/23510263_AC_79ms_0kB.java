import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {


	static int aldeas[];

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int casos;
		StringTokenizer tk;
		tk = new StringTokenizer(bf.readLine());
		casos = Integer.parseInt(tk.nextToken());
		for (int i = 0; i < casos; i++) {
			aldeas = new int[20];
			tk = new StringTokenizer(bf.readLine());
			for (int j = 0; j < 20; j++) {
				aldeas[j] = Integer.parseInt(tk.nextToken());
			}

			for (int j = 0; j < 20; j++) {
				if (aldeas[j]  > 1) {
					recorrer(j);
				}
			}
			for (int j = 0; j < 19; j++) {
				System.out.print(aldeas[j]  + " ");
			} System.out.print(aldeas[19]);
			System.out.println();
		}
	}

	static void recorrer(int i ) {
		if (i == 0) return;
		int temp = aldeas[i];
		aldeas[i] = temp%2;
		temp/= 2;
		i--;
		while (i >= 0 && temp > 0 ) {
			if (i == 0) aldeas[i] += temp;
			else {
				temp += aldeas[i];
				aldeas[i] = temp%2;
				temp /= 2;
			}
			i--;

		}
	}
}
