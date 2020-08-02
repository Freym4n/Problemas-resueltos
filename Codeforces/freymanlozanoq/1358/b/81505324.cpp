
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m;
    cin >> n;
    int a[n];
    for(int i = 0; i< n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    int grannies = 1;
    int ans = 1;
    for(int i = 0; i < n; i++) {
        if (a[i] <= grannies) {
            grannies = (i+2);
            ans = grannies;
        } else {
            grannies ++;
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
