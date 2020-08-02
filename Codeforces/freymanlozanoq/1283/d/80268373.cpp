#include <bits/stdc++.h>

using namespace std;

int MAX  = 2e9;

void solve() {
    int n,m;
    cin >> n >> m;
    int in[n];
    set<int> s;
    queue< pair<int,int>> q;
    for(int i = 0; i < n; i++) {
        cin >> in[i];
        s.insert(in[i]);
        q.push({in[i],0});
    }
    int cont = 0;
    long long ans = 0;
    pair<int, int> current;
    vector <int> p;
    while(cont < m) {
        current = q.front();
        q.pop();
        int idx = current.first;
        int dist = current.second;
        if (dist != 0) {
            ans += dist;
            cont++;
            p.push_back(idx);
        }
        if (idx + 1 <= MAX && s.count(idx + 1) == 0) {
            q.push({idx+1,dist+1});
            s.insert(idx+1);
        }
        if (idx - 1 <= MAX && s.count(idx - 1) == 0) {
            q.push({idx-1,dist+1});
            s.insert(idx-1);
        }
    }
    cout << ans << "\n";
    for(int i = 0; i < m; i++) {
        cout << p[i];
        if (i  < m - 1 ) cout << " ";
    } cout << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
