#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> ans;
    for(int p = 2; p*p <= n && ans.size() < k-1; p++) {
        while(n % p == 0 && ans.size() < k-1) {
            ans.push_back(p);
            n /= p;
        }
    }
    if (ans.size() < k-1 || n  == 1) {
        cout << "-1\n";
        return;
    }
    for(int d : ans) cout << d <<  ' ';
    cout << n << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    //cin >> t; while(t--) solve();
    solve();

}
