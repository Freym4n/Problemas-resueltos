
#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x1,x2,y1,y2,x,y;
    cin >> x1 >> y1 >> x2 >> y2;
    x = x2 - x1 + 1;
    y = y2 - y1 + 1;
    long long low = min(x,y);
    long long high = max(x,y);
    long long sim = max((long long)0,low - 2) ;
    sim = (sim+1)*sim;
    //cout << sim << " sim\n";
    long long asim = high - low + 1;
    asim = asim*(low-1);
    long long ans = asim + sim;
    cout << (ans+1) << "\n";

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
