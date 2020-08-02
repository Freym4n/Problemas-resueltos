
#include <bits/stdc++.h>

using namespace std;


bool check(vector<string> &s, string ans ) {
    int n = s.size();
    int m = s[0].size();
    for(int i = 0;i <n; i++) {
        int cont = 0;
        for(int j =  0; j <  m; j++) {
            if (s[i][j] != ans[j]) cont++;
        }
        if (cont > 1) return false;
    } return true;
}

void solve() {
    int n,m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i <n; i++) {
        cin >> s[i];
    }
    string base = s[0];
    bool possible = false;
    for(int i = 0; i < m; i++) {
        string ans = base;
        for(int j = 0; j < n; j++) {
            ans[i] = s[j][i];
            possible |= check(s,ans);
            if (possible) {
                cout << ans << "\n";
                return;
            }
        }
    }
    cout << "-1\n";


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
