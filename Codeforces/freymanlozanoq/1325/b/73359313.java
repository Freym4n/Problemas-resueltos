import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bf.readLine()),x;
		TreeMap<Integer, Integer>  lst = new TreeMap<Integer, Integer>();
		StringTokenizer tk;
		for (int i = 0; i < n; i++) {
			lst.clear();
			x = Integer.parseInt(bf.readLine());
			tk = new StringTokenizer(bf.readLine());
			for (int j = 0; j < x; j++) {
				lst.put(Integer.parseInt(tk.nextToken()), 1);
			}
			System.out.println(lst.size());
			
			
		}
	}
}
