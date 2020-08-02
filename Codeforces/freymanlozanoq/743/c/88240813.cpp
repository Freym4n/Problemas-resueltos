#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "-1\n";
        return;
    }
    cout << n << ' ' << n+1 << ' ' << n*(n+1) << '\n';

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
