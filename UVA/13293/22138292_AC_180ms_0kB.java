import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main  implements Comparable<Main>{
	String Nombre;
	int Puntos;

	public Main(String nombre, int puntos) {
		this.Nombre = nombre;
		this.Puntos = puntos;
	}

	public int compareTo(Main o) {
		if(this.Puntos == o.Puntos) {
			return this.Nombre.toLowerCase().compareTo(o.Nombre.toLowerCase());
		} 					
		else if(this.Puntos > o.Puntos){
			return -1;
		} else {
			return 1;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int iteracion = 1;
		String[] linea;
		String nombreCompleto;
		int puntos;
		Main k[];
		while (bf.ready()) {
			int numeroJug = Integer.parseInt(bf.readLine());
			k= new Main[numeroJug];
			for (int i = 0; i < numeroJug; i++) {
				linea = bf.readLine().split(";");
				nombreCompleto = linea[0];
				puntos = 0;
				for (int j = 1; j < linea.length; j++) {
					puntos += leerPuntos(linea[j]);
				}
				k[i] = new Main(nombreCompleto,puntos);
			}
			Arrays.sort(k);
			System.out.println("Case "+iteracion+":");
			iteracion++;
			for (int i = 0; i < k.length; i++) {
				System.out.print(k[i].toString());
			}
		}
	}

	public static int leerPuntos(String s) {
		int puntos = 0;
		String[] set = s.split(" ");
		for (int i = 0; i < set.length; i++) {
			puntos += Integer.parseInt(set[i]);
		}
		if (set[4].equals("1") ) {
			puntos++;
		}
		return puntos;
	}

	public String toString() {
		return  this.Nombre +" "+this.Puntos+"\n";
	}
}