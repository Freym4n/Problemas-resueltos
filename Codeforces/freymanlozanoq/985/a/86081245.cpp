#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n/2];
    for(int i = 0; i < n/2; i++) {
        cin >> a[i];
    }
    int ansp = 0;
    sort(a, a + n/2);
    //pares
    for(int i = n/2-1; i >= 0; i--) {
        ansp += abs(a[i]-(i*2 + 2));
    }
    int ansi = 0;
    for(int i = n/2-1; i >= 0; i--) {
        ansi += abs(a[i] - (i*2 + 1));
    }
    int ans = min(ansp,ansi);
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin >> t;
    //while(t--) {
        solve();
    //}
}
