#include <bits/stdc++.h>

using namespace std;
// para crear estructuras estaticas debemos definirle un tamaño inicial, para ello colocamos el tamaño maximo del ejercicio
int const MAX_N = 200001;
vector<vector<int>> lst (MAX_N);
int tf[MAX_N];
int ti[MAX_N];
int parent[MAX_N];
//tener las estructuras estaticas nos permite tener menos parametros en el dfs y hacerlo mas liviano de implementar
int n;
int k;
int t = 0;

//recorremos el arbol y calculamos los tiempos de llegada y salida de cada nodo, asi como el padre directo de cada nodo
void dfs(int current) {
    ti[current] = t++; //tiempo de entrada al nodo
    for(int v: lst[current]) {
        if (v != parent[current]) {
            parent[v] = current; //el nodo a visitar tendra como padre el nodo actual
            dfs(v);
        }
    }
    tf[current] = t++; //tiempo de salida
}

//checkear si el nodo x esta contenido en el nodo y (si y es ancestro de x)
bool is_ok(int xi, int xf, int yi, int yf) {
    return xi >= yi && xf <= yf; //mirar si uno contiene al otro a nivel de rangos
}


bool solve(vector<int> &q, int len) {
    int node, max_ti;
    //tomamos el nodo mas profundo (con mayor ti en caso que todos los nodos pasen por el mismo camino)
    node = q[0];
    max_ti = ti[q[0]];
    for(int i = 0; i < len; i++) {
        if (max_ti < ti[q[i]]) {
            max_ti = ti[q[i]];
            node = q[i];
        }
    }
    //miramos si el nodo mas profundo es hijo de todos los demas
    for(int i: q) {
        if (!is_ok(ti[node], tf[node],ti[i], tf[i])) return false;
    }
    //si es hijo, retornamos true
    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    //leemos el arbol
    for(int i = 0; i < n - 1 ; i++) {
        int nodo1, nodo2;
        cin >> nodo1 >> nodo2;
        lst[nodo1-1].push_back(nodo2-1);
        lst[nodo2-1].push_back(nodo1-1);
    }
    //calculamos los tiempos y padres
    dfs(0);
    //resolvemos cada query
    while(k--) {
        int len;
        cin >> len;
        vector<int> query (len);
        for(int i = 0; i <len; i++) {
            cin >> query[i];
        }
        for(int i = 0; i < len; i++) {
            query[i] = parent[query[i]-1]; // trabajamos con parientes para solucionar el problema del 1 de distancia
        }
        if (solve(query,len))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
