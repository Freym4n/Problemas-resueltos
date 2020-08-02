#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    int e[n];
    for(int i = 0; i<  n; i++) {
        cin >> e[i];
    }
    sort(e, e + n);
    int last_idx = -1;
    int ans = 0;
    for(int i =0 ; i < n; i++) {
        if (e[i] <= i - last_idx) {
            ans++;
            last_idx = i;
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
