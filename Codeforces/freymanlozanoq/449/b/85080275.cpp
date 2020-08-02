#include <bits/stdc++.h>

using namespace std;

long long const INF = 1e18;

void shortest_path(int src, vector<long long> &dist, vector<vector<pair<long long,int>>> &lst, vector<int> &parent) {
    priority_queue<pair<long long, int>> q;
    dist[src] = 0;
    parent[src] = 0;
    q.push({0,src});
    while(!q.empty()) {
        pair<long long, int> temp = q.top();
        q.pop();
        int id = temp.second;
        if (dist[id] != abs(temp.first)) continue;
        for(pair<long long,int> v: lst[id]) {
            if (dist[v.second] > dist[id] + v.first) {
                dist[v.second] = dist[id] + v.first;
                parent[v.second] = id;
                q.push({-dist[v.second],v.second});
            } else if(dist[v.second] == dist[id] + v.first) {
                parent[v.second] = max(id, parent[v.second]);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<long long, int>>> lst (n);
    vector<long long> td(n,0);
    vector<int> parent (n);
    vector<long long> dist (n,INF);
    for(int i = 0; i < m; i++) {
        int from,to; long long w;
        cin >> from >> to >> w;
        lst[from-1].push_back({w,to-1});
        lst[to-1].push_back({w,from-1});
    }
    int ans = 0;
    shortest_path(0,dist,lst,parent);
    for(int i = 0; i < k; i++) {
        int to; long long w;
        cin >> to >> w;
        to--;
        if (td[to] == 0 ) td[to] = w;
        else {
            td[to] = min(td[to],w);
            ans++;
        }
    }
    for(int i = 0; i <n; i++) {
        if (td[i] == 0)  continue;
        if (td[i] >= dist[i]) {
            ans++;
            td[i] = 0;
        }
        else lst[0].push_back({td[i],i});
    }
    dist.assign(n,INF);
    shortest_path(0,dist,lst,parent);
    for(int i = 0; i <n; i++) {
        if (td[i] == 0) continue;
        if (dist[i] == td[i] && parent[i] == 0) continue;
        ans++;
    }
    cout << ans << "\n";

}
