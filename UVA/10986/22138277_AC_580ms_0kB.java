import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		try {
			int nodos, edges, from, to,result[],r, w, t, f, casos = Integer.parseInt(bf.readLine());
			String linea[];
			Vertex G[];
			for (int i = 0; i < casos; i++) {
				linea = bf.readLine().split(" ");
				nodos = Integer.parseInt(linea[0]);
				edges = Integer.parseInt(linea[1]);
				from = Integer.parseInt(linea[2]);
				to = Integer.parseInt(linea[3]);
				G = new Vertex[nodos];
				for (int j = 0; j < G.length; j++) {
					G[j] = new Vertex();
				}
				for (int j = 0; j < edges; j++) {
					linea = bf.readLine().split(" ");
					f = Integer.parseInt(linea[0]);
					t = Integer.parseInt(linea[1]);
					w = Integer.parseInt(linea[2]);
					G[f].adj.add(new Edge(t,w));
					G[t].adj.add(new Edge(f,w));
				}
				Dijkstra d = new Dijkstra(G,nodos);
				result = d.dijkstra(from);
				r = result[to];
				System.out.println("Case #"+(i+1)+": "+(r==500000?"unreachable":r));
				

			}
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		Vertex[] G = new Vertex[4];
		//		Edge k1 = new Edge(1, 1);
		//		Edge k2 = new Edge(2, 1);
		//		Edge k3 = new Edge(3, 1);
		//		Edge k4 = new Edge(4, 1);
		//		ArrayList<Edge> Nodo1=new ArrayList();
		//		Nodo1.add(k2);
		//		Nodo1.add(k3);
		//		ArrayList<Edge> Nodo2=new ArrayList();
		//		Nodo2.add(k4);
		//		Nodo2.add(k1);
		//		ArrayList<Edge> Nodo3=new ArrayList();
		//		Nodo3.add(k4);
		//		Nodo3.add(k1);
		//		ArrayList<Edge> Nodo4=new ArrayList();
		//		Nodo4.add(k3);
		//		Nodo4.add(k2);
		//		G[0]= new Vertex(Nodo1);
		//		G[1]= new Vertex(Nodo2);
		//		G[2]= new Vertex(Nodo3);
		//		G[3]= new Vertex(Nodo4);
		//		Dijkstra Ej1 = new Dijkstra(G,4);
		//		System.out.println(Ej1.dijkstra(2));
	}
}

class Vertex {

	List< Edge> adj;

	public Vertex() {
		adj = new ArrayList< Edge>();
	}
	public Vertex(ArrayList< Edge> k) {
		adj = k;
	}

}

class Edge {

	int to, w;

	public Edge(int to, int w) {
		this.to = to;
		this.w = w;
	}
}

class QueueItem implements
Comparable< QueueItem> {

	int u, dist;

	public QueueItem(int u, int dist) {
		this.u = u;
		this.dist = dist;
	}

	public int compareTo(QueueItem q) {
		return this.dist - q.dist;
	}
}

class Dijkstra {
	int N;
	static int INF=500000;
	Vertex[] G;
	public Dijkstra() {
		N = 0;
		G = null;

	}

	public Dijkstra(Vertex[] G1, int N1) {
		this.G = G1;
		this.N = N1;
	}
	int[] dijkstra(int s) {
		int[] dist = new int[N];
		int[] p = new int[N];
		PriorityQueue< QueueItem> Q = new PriorityQueue< QueueItem>();
		Arrays.fill(dist, INF);
		Arrays.fill(p, -1);
		dist[s] = 0;
		Q.offer(new QueueItem(s, 0));
		while (!Q.isEmpty()) {
			QueueItem q = Q.poll();
			int u = q.u, d = q.dist;
			if (d == dist[u]) {
				for (Edge e : G[u].adj) {
					int v = e.to, w = e.w;
					if (dist[u] + w < dist[v]) {
						dist[v] = dist[u] + w;
						p[v] = u;
						Q.offer(new QueueItem(v, dist[v]));
					}
				}
			}
		}
		return dist;
	}
}