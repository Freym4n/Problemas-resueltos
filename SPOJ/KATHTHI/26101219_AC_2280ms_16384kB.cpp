#include <bits/stdc++.h>

using namespace std;

long long const INF = 1e18;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n,m;

bool is_ok(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void shortest_path(vector<vector<long long>> &dist, vector<string> &g) {
    dist[0][0] = 0;
    deque<pair<int,int>> q;
    q.push_front({0,0});
    while (!q.empty()) {
        int y = q.front().first;
        int x= q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int y1 = y + dy[i];
            int x1 = x + dx[i];
            if (!is_ok(x1,y1)) continue;
            int w = (g[y1][x1] == g[y][x]?0:1);
            if (dist[y][x] + w < dist[y1][x1]) {
                dist[y1][x1] = dist[y][x] + w;
                if (w == 1)
                    q.push_back({y1,x1});
                else
                    q.push_front({y1,x1});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i <n; i++) {
        cin >> g[i];
    }
    vector<vector<long long>> dist (n, vector<long long> (m,INF));
    shortest_path(dist,g);
    long long ans = dist[n-1][m-1];
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

}
