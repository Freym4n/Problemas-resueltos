#include <bits/stdc++.h>

using namespace std;

long long const m =  1e9 + 7;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> a (n);
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    int cont_a = 0;
    bool esquina = 0,borde = 0,existe = 0, columna = 0, pila = 0;
    vector<int> filas (n,0), columnas (m,0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m;j++) {
            if (a[i][j] == 'P') continue;
            existe = 1;
            if ((i == 0 || i == n - 1) && (j == 0 || j == m-1)) esquina = 1;
            if (i == 0 || i == n-1 || j == 0 || j == m - 1) borde = 1;
            filas[i]++;
            columnas[j]++;
            cont_a++;
        }
    }
    for(int i = 0; i < n; i++) {
        if (filas[i] == m) pila = 1;
    }
    for(int i = 0; i < m; i++) {
        if (columnas[i] == n) pila = 1;
    }
    if (cont_a == n*m)
        cout << "0\n";
    else if (filas[0] == m || filas[n-1] == m || columnas[0] == n || columnas[m-1] == n)
        cout << "1\n";
    else if (esquina || pila)
        cout << "2\n";
    else if (borde)
        cout << "3\n";
    else if (existe)
        cout << "4\n";
    else {
        cout << "MORTAL\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

}
