
#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n; cin >> n;
    vector<string> v (n);
    for(int i = 0; i <n; i++) {
        cin >> v[i];
    }
    bool possible = true;
    for(int i = 0; i <n; i++) {
        for(int j = 0; j < n; j++) {
            if (v[i][j] == '1') {
                if (i == n-1 || j == n -1) continue;
                if (i < n && v[i+1][j] == '1') continue;
                if (j < n && v[i][j+1] == '1') continue;
                possible = false;
            }
        }
    }
    cout << (possible?"YES":"NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
