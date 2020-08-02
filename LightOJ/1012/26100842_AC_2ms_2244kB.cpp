
#include <bits/stdc++.h>

using namespace std;


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

bool is_ok(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int bfs(vector<string> &g, int i, int j) {
    queue<pair<int,int>> q;
    g[i][j] = '1';
    q.push({i,j});
    int ans = 0;
    while(!q.empty()) {
        pair<int,int> temp = q.front(); q.pop();
        int x = temp.second;
        int y = temp.first;
        ans++;
        for(int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (!is_ok(x1,y1)) continue;
            if (g[y1][x1] != '.') continue;
            g[y1][x1] = '1';
            q.push({y1,x1});
        }
    }
    return ans;
}

void solve(int test_case) {
    cin >> m>> n;
    vector<string> g(n);
    int x = 0,y = 0;
    for(int i = 0; i <n; i++) {
        cin >> g[i];
        for(int j =0; j <m; j++)
            if (g[i][j] == '@') {
                x = j;
                y = i;
            }
    }
    int ans = bfs(g, y,x);
    cout << "Case " << test_case << ": " << ans << "\n";


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <=t ; i++) {
        solve(i);
    }
}

