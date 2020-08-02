#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string op;
    for(int i = 0; i <n; i++) {
        if(op.empty()) {
            op.push_back(s[i]);
        } else {
            if (op.back() == '(' && s[i] == ')') {
                op.pop_back();
            } else {
                op.push_back(s[i]);
            }

        }
    }
    int ans = op.size()/2;
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
