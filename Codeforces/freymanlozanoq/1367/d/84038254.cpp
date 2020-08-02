
#include <bits/stdc++.h>

using namespace std;


void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(s.rbegin(),s.rend());
    int n =s.size();
    vector<int> rep(n,0);
    rep[n-1] = 1;
    for(int i = n- 2; i >= 0; i--) {
        if (s[i] == s[i+1]) rep[i] = rep[i+1] + 1;
        else rep[i] = 1;
    }
    int max_l = 0;
    string ans (m,'_');
    while(max_l < n) {
        vector<int> ceros;
        for(int i = 0; i < m; i++) {
            if (b[i] == 0 && ans[i] == '_') {
                ceros.push_back(i);
            }
        }
        int len = ceros.size();
        while(rep[max_l] != len) {
            max_l++;
        }
        for(int i: ceros) {
            ans[i] = s[max_l++];
        }
        if (ceros.empty()) break;
        for(int i: ceros) {
            for(int j = 0; j < m; j++) {
                b[j] -= abs (j - i);
            }
        }
    }
    cout << ans << "\n";



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

