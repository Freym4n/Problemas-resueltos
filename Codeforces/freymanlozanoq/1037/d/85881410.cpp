#include <bits/stdc++.h>

using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> lst (n);
    for(int i = 0; i < n - 1; i++) {
        int from,to;
        cin >> from >> to;
        lst[from-1].push_back(to-1);
        lst[to-1].push_back(from-1);
    }
    vector<int> path (n);
    vector<int> dist (n,-1);
    for(int i = 0; i <n; i++) {
        cin >> path[i];
        path[i]--;
    }
    queue<int> q;
    q.push(0);
    dist[0] =0;
    bool valid = true;
    if (path[0] != 0) valid = false;
    int idx = 1;
    while(!q.empty() && valid) {
        int node  = q.front(); q.pop();
        set<int> s;
        for(int v: lst[node]) {
            if (dist[v] == -1) {
                dist[v] = dist[node] + 1;
                s.insert(v);
            }
        }
        int len = s.size();
        for(int j = 0; j < len; j++) {
            if (!s.count(path[idx])) valid = false;
            q.push(path[idx]);
            idx++;

        }


    }

    cout << (valid?"Yes":"No") << "\n";



}
