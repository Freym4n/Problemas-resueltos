#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    string t;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i <n; i++) {
        if (t.empty()) t.push_back(s[i]);
        else {
            if (s[i] != t.back()) {
                t.pop_back();
                ans++;
            } else {
                t.push_back(s[i]);
            }
        }
    }
    if (ans%2 == 0) {
        cout << "NET\n";
    } else {
        cout << "DA\n";
    }

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
