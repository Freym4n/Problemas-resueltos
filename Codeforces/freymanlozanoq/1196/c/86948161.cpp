#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n;
    cin >> n;
    int xl = -100000, xr = 100000, yl = -100000, yr = 100000;
    int x,y,l,u,r,d;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        cin >> l >> u >> r >> d;
        if (l == 0) xl = max(xl,x);
        if (r == 0) xr = min(xr,x);
        if (u == 0) yr = min(yr,y);
        if (d == 0) yl = max(yl,y);
    }
    if (yl > yr || xl > xr) cout << "0\n";
    else cout <<"1 "<<xl << " " << yl << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    //solve();

}
