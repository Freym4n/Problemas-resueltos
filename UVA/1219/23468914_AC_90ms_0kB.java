import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Player {
	int id; String name; char role; int time;


	public Player(int id, String name, char role, int time) {
		super();
		this.id = id;
		this.name = name;
		this.role = role;
		this.time = time;
	}

	@Override
	public String toString() {
		return id + " " + name + " " + role;
	}



}
public class Main {

	static ArrayList<Player> G = new ArrayList<Player>();
	static ArrayList<Player> D = new ArrayList<Player>();
	static ArrayList<Player> M = new ArrayList<Player>();
	static ArrayList<Player> S = new ArrayList<Player>();
	static Player[] equipo;

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk = new StringTokenizer(bf.readLine());
		int number; String nombre; char role; int time;
		int nD, nM, nS;
		Player temp;
		String linea[];
		while(tk.countTokens()  > 1) {
			G.clear();
			D.clear();
			M.clear();
			S.clear();
			for(int i = 0; i < 22; i++) {
				number = Integer.parseInt(tk.nextToken());
				nombre = tk.nextToken();
				role = tk.nextToken().charAt(0);
				time = solveTime(tk);
				temp = new Player(number, nombre, role, time);
				switch(role) {
				case 'G':
					G.add(search(temp.id,G),temp);
					break;
				case 'D':
					D.add(search(temp.id, D),temp);
					break;
				case 'M':
					M.add(search(temp.id,M),temp);
					break;
				case 'S':
					S.add(search(temp.id,S),temp);
					break;
				} tk = new StringTokenizer(bf.readLine());
			} 
			linea = tk.nextToken().split("-");
			nD = Integer.parseInt(linea[0]);
			nM = Integer.parseInt(linea[1]);
			nS = Integer.parseInt(linea[2]);
			if (nD  > D.size() || nM > M.size() || nS > S.size() || G.size() == 0 || (nM + nS + nD != 10)) {
				System.out.println("IMPOSSIBLE TO ARRANGE");
			} else {
				equipo = new Player[11];
				equipo[0] = G.get(0);
				for (int i = 1; i < nD + 1; i++) 
					equipo[i] = D.remove(0);
				for (int i = 1 + nD; i < 1 + nD + nM; i++) 
					equipo[i] = M.remove(0);
				for(int i = 1 + nD + nM; i < 1+ nD + nM + nS; i++)
					equipo[i] = S.remove(0);

				temp = equipo[0];
				int primero = 0;
				for (int i = 1; i < 11; i++) {
					if (equipo[i].time > temp.time || (equipo[i].time == temp.time && equipo[i].id > temp.id)) {
						temp = equipo[i];
						primero = i;
					}
				}
				System.out.println(equipo[primero].toString());
				for (int i = 0; i < 11; i++) {
					if (i == primero) continue;
					System.out.println(equipo[i].toString());
				}
			}
			System.out.println();
			tk = new StringTokenizer(bf.readLine());
		}
	}

	static int search(int x, ArrayList<Player> lst) {
		if (lst.isEmpty()) 
			return 0;
		int l = 0, r = lst.size()-1, mid = r/2;
		int temp;
		while(l <= r) {
			temp = lst.get(mid).id;
			if (temp > x) {
				r = mid - 1;
			} else {
				l = mid + 1;
			} mid = l + (r-l)/2;
		} return mid;
	}

	static int solveTime(StringTokenizer tk) {
		int n = tk.countTokens();
		int time = 0;
		String periodo[];
		for (int i = 0; i < n; i++) {
			periodo = tk.nextToken().split("-");
			time += Integer.parseInt(periodo[1]) - Integer.parseInt(periodo[0]) + 1;
		} return time;
	}

}
