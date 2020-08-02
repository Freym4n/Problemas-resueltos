import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


class Point {
	int x, w;

	public Point(int x, int w) {
		super();
		this.x = x;
		this.w = w;
	}
}
public class Main {
	static Queue<Point> q;
	static int limit;


	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk;
		int casos = Integer.parseInt(bf.readLine()),puntos,x,w;
		for (int i = 0; i < casos; i++) {
			q = new LinkedList<Point>();
			tk = new StringTokenizer(bf.readLine());
			limit = Integer.parseInt(tk.nextToken());
			puntos = Integer.parseInt(tk.nextToken());
			for (int j = 0; j < puntos; j++) {
				tk = new StringTokenizer(bf.readLine());
				x = Integer.parseInt(tk.nextToken());
				w = Integer.parseInt(tk.nextToken());
				q.add(new Point(x,w));
			}
			System.out.println(solve());
		}
	}
	
	static int solve() {
		int dist = 0;
		while(!q.isEmpty()) {
			dist += recorrer();
		} return dist;
	}
	
	static int recorrer() {
		int disp = limit;
		int dist = 0;
		Point p;
		while(!q.isEmpty() && disp > 0) {
			p = q.peek();
			dist = p.x;
			if (q.peek().w <= disp) {
				disp -= p.w;
				q.poll();
			} else {
				return dist*2;
			}
		} return dist*2;
	}
}
