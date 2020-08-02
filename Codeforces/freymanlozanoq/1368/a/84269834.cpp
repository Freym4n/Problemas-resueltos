
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int a,b,n;
    cin >> a >> b >> n;
    int ans  = 0;
    if (a > b) swap(a,b);
    while(a <= n && b <= n) {
        ans++;
        if((ans&1)) {
            a += b;
        } else {
            b += a;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}

