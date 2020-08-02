#include <bits/stdc++.h>

using namespace std;

int n,m;

bool is_ok(int i, int j) {
    return i  < n && j < m && i >= 0 && j >= 0;
}

void solve() {
    cin >> n >> m;
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,1,0,-1};
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    bool possible = true;
    for(int i = 0; i <n; i++) {
        for(int j = 0; j <m; j++) {
            if(a[i][j] <= 0) continue;
            if (a[i][j] > 4) possible = false;
            int cont = 0;
            int disp = 0;
            for(int d = 0; d < 4; d++) {
                int vi = i + dy[d];
                int vj = j + dx[d];
                if (!is_ok(vi,vj)) continue;
                if (a[vi][vj] > 0) cont++;
                disp++;
            }
            if (disp < a[i][j]) possible = false;
            int done = 0;
            for(int d = 0; d < 4 && done < a[i][j]-cont; d++) {
                int vi = i + dy[d];
                int vj = j + dx[d];
                if (!is_ok(vi,vj)) continue;
                if (a[vi][vj] > 0) continue;
                a[vi][vj] = 1;
                done++;
            }
        }
    }
    for(int i = 0; i <n; i++) {
        for(int j = 0; j <m; j++) {
            if (a[i][j] <= 0) continue;
            int cont = 0;
            for(int d = 0; d < 4; d++) {
                int vi = i + dy[d];
                int vj = j + dx[d];
                if (!is_ok(vi,vj)) continue;
                if (a[vi][vj] > 0) cont++;
            }
            a[i][j] = cont;
        }
    }
    if (!possible) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 0; i <n; i++) {
        for(int j = 0; j <m; j++) {
            cout << a[i][j] << " ";
        } cout << "\n";
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
