#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> a (n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v (m,0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '0') continue;
            v[j]++;
        }
    }
    bool possible = false;
    for(int i = 0; i < n; i++) {
        bool needed = false;
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '0') continue;
            if(v[j] == 1) needed = true;
        }
        if (!needed) possible = true;
    }
    cout << (possible?"YES":"NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin >> t;
    //while(t--) {
        solve();
    //}
}
