
#include <bits/stdc++.h>

using namespace std;


int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};
int n,m;

bool is_ok(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void bfs(vector<string> &g, int i, int j) {
    queue<pair<int,int>> q;
    g[i][j] = '1';
    q.push({i,j});
    while(!q.empty()) {
        pair<int,int> temp = q.front(); q.pop();
        int x = temp.second;
        int y = temp.first;
        for(int i = 0; i <8; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (!is_ok(x1,y1)) continue;
            if (g[y1][x1] != '@') continue;
            g[y1][x1] = '1';
            q.push({y1,x1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    while(n + m > 0) {
        vector<string> g (n);
        for(int i = 0; i <n; i++) cin >> g[i];
        int cont = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (g[i][j] != '@' ) continue;
                bfs(g,i,j);
                cont++;;
            }
        }
        cout << cont << "\n";
        cin >> n >> m;
    }

}

