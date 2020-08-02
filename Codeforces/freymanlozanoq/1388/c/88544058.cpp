#include <bits/stdc++.h>

using namespace std;

int const N = 1e5+1;
vector<long long> tp(N),rh(N),p(N),h(N);
long long sum_tp;
bool possible;
void dfs(int node, int parent, vector<vector<int>> &lst) {

    tp[node] = sum_tp;
    sum_tp += p[node];

    for(int v: lst[node]) if (v != parent) dfs (v,node,lst);

    tp[node] = sum_tp - tp[node];

    if ((tp[node] + h[node]) % 2 != 0) possible = false;
    rh[node] = (tp[node] + h[node])/2;
    if (rh[node] < 0 || rh[node]  > tp[node]) possible = false;
}



void dfs2(int node, int parent, vector<vector<int>> &lst) {

    long long sum_srh = 0;

    for(int v: lst[node]) if (v != parent) {
        dfs2(v,node,lst);
        sum_srh += rh[v];
    }

    if (sum_srh > rh[node]) possible = false;
}

void solve() {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<vector<int>> lst (n);
    for(int i = 0; i < n - 1 ; i++) {
        int to,from;
        cin >> from >> to;
        --from; --to;
        lst[from].push_back(to);
        lst[to].push_back(from);
    }
    possible = true;
    sum_tp = 0;
    dfs(0,-1,lst);
    dfs2(0,-1,lst);
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) solve();
    //solve();
}



