#include <bits/stdc++.h>

using namespace std;



void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (s[n-1] == 'o') {
        cout << "FILIPINO\n";
        return;
    }
    if (s[n-1] == 'u') {
        cout << "JAPANESE\n";
        return;
    }
    cout << "KOREAN\n";

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
