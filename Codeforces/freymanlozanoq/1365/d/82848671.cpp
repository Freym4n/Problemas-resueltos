
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

int n,m;



int bfs(vector<string> &a, pair<int,int> src) {
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    queue<pair<int,int>> q;
    bool v[n][m];
    memset(v,false, sizeof(v));
    if (a[src.first][src.second] != '#') {
        q.push(src);
    }
    v[src.first][src.second] = true;
    int cont = 0;
    if (a[src.first][src.second ] == 'G') {
        cont++;
    }
    while(!q.empty()) {
        pair<int,int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        for(int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (y1 >= m || x1 >= n || x1 < 0 || y1 < 0) continue;
            if (!v[x1][y1] && a[x1][y1] != '#') {
                v[x1][y1] = true;
                q.push({x1,y1});
                if (a[x1][y1] == 'G') {
                    cont++;
                }
            }
        }

    }
    return cont;
}

void solve() {
    cin >> n >> m;
    vector<string> a (n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool possible = true;
    for(int i = 0; i  < n; i++) {
        for(int j = 0; j <m; j++) {
            if (a[i][j] == 'B') {
                for(int d = 0; d < 4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if (x >= n || y >= m || x < 0 || y < 0) continue;
                    if (a[x][y] == 'G') possible = false;
                    if (a[x][y] == '.') a[x][y] = '#';
                }
            }
        }
    }
    if (!possible) {
        cout << "No\n";
        return;
    }
    int cont1 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (a[i][j] == 'G') {
                cont1++;
            }
        }
    }
    int cont = bfs(a,{n-1,m-1});
    if (cont == cont1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
