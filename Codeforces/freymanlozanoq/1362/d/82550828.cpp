
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */




void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> ans;
    vector<vector<int>> lst (n+1);
    vector<int> t (n+1);
    int from,to1;
    for(int i = 0; i < m; i++) {
        cin >> from >> to1;
        lst[from-1].push_back(to1-1);
        lst[to1-1].push_back(from-1);
    }
    vector<vector<int> > to (n+1);
    for(int i =0 ; i <n; i++) {
        cin >> t[i];
        to[t[i]].push_back(i);
    }
    bool possible = true;
    vector<bool> v (n+1);
    for(int i = 1; i <= n; i++) {
        for(int j: to[i]) {
            //verificar
            set<int> s;
            for(int vec: lst[j]) {
                if (t[vec] == t[j]) {
                    possible = false;
                }
                if (t[vec] < t[j] && v[vec])
                    s.insert(t[vec]);
            }
            if (s.size() == t[j]-1) {
                ans.push_back(j);
                v[j] = true;
            } else {
                possible = false;
            }
        }
    }
    if (possible) {
        for(int i = 0; i < n; i++) {
            cout << (ans[i]+1);
            if (i < n) cout << " ";
        } cout << "\n";
    } else {
        cout << "-1\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
