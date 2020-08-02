
#include <bits/stdc++.h>

using namespace std;



void solve() {
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    long long ans  = 0;
    if (e > f) {
        int cnt = min(a, d);
        ans += cnt*e;
        a -= cnt;
        d -= cnt;
        ans += (min(b,min(c,d))*f);
    } else {
        int cnt = min(b,min(c,d));
        ans += cnt*f;
        b -= cnt;
        c -= cnt;
        d -= cnt;
        ans += (min(a,d)*e);
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();

}

