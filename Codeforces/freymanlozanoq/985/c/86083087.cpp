#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,k; long long l;
    cin >> n >> k >> l;
    long long a[n*k];
    for(int i = 0; i < n*k; i++ ) {
        cin >> a[i];
    }
    sort(a, a + n*k);
    int idx  = 0;
    for(int i = 1; i < n*k - k + 1; i++) {
        if (a[i] <= a[0]+l) idx = i;
    }
    if (idx < n - 1) {
        cout << "0\n";
        return;
    }
    long long ans = 0;
    int b = 0;
    int i = 0;
    while(n - b < idx - i + 1) {
        if (i%k==0) {
            b++;
            ans += a[i];
        }
        i++;
    }
    for(; i <= idx; i++) {
        ans += a[i];
    }
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
