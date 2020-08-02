
#include <bits/stdc++.h>

using namespace std;


void solve() {
    string s;
    cin >> s;
    string ans;
    ans.push_back(s[0]);
    ans.push_back(s[1]);
    for(int i = 3; i < s.size();i+=2) {
        ans.push_back(s[i]);
    }
    cout << ans<< "\n";
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

