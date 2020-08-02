#include <bits/stdc++.h>

using namespace std;

long long const inf = 1e9;

void solve()  {
    long long n,x,y,d;
    cin >> n >> x >> y >> d;
    if (abs(x-y)%d == 0) {
        cout << (abs(x-y)/d) << "\n";
        return;
    }
    long long ans = inf;
    if ((y-1)%d == 0) {
        ans = (x + d - 2)/d + (y + d - 2)/d;
    }
    if ((y-n)%d == 0) {
        ans = min(ans,(n-x + d - 1)/d + (n-y + d - 1)/d);
    }
    if (ans == inf) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }

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
