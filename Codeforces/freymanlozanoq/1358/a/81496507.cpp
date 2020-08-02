
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    int ans = (n/2)*m;
    if (n&1) {
        ans += (m+1)/2;
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
