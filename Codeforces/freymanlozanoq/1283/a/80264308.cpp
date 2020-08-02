#include <bits/stdc++.h>

using namespace std;


void solve() {
    int h,m;
    cin >> h >> m;
    int total = h*60 + m;
    int ans = 1440 - total;
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
