
#include <bits/stdc++.h>

using namespace std;

int n,m;

int bfs(vector<vector<int>> &lst, int src, vector<int> &dist) {
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for(int v : lst[node]) {
            if (dist[v] == -1) {
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> lst (n);
    for(int i = 0; i <m; i++) {
        int from,to;
        cin >> from >> to;
        lst[from-1].push_back(to-1);
        lst[to-1].push_back(from-1);
    }
    vector<int> dist(n,-1);
    bfs(lst,0, dist);
    int ans = dist[n-1] -1 ;
    cout << ans << "\n";
}

