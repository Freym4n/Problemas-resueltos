
#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,m,x;
    cin >> n >> x >> m;
    long long ans = 0;
    int l,r;
    int high = x, low = x;
    while(m--) {
        cin >> l >> r;
        if (r < low || l > high) continue;
        low = min(l,low);
        high = max (r,high);
    }
    ans = high - low + 1;
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
