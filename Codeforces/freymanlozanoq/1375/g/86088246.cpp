#include <bits/stdc++.h>

using namespace std;

int n;

void solve() {



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<vector<int>> lst (n);
    for(int i = 0; i < n - 1; i++) {
        int to,from;
        cin >> from >> to;
        lst[from-1].push_back(to-1);
        lst[to-1].push_back(from-1);
    }
    queue<int> q;
    vector<int> depth(n,-1);
    depth[0] = 0;
    q.push(0);
    int odd = 0,even = 1;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for(int v: lst[node]) if (depth[v] == -1 ){
            depth[v]= depth[node] + 1;
            q.push(v);
            if (depth[v]%2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
    }
    cout << min(odd,even)-1 << "\n";


}
