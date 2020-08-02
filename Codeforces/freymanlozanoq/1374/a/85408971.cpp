#include <bits/stdc++.h>

using namespace std;



void solve() {
    long long x,y,n;
    cin >> x >> y >> n;
    n -= y;
    n/=x;
    n*=x;
    n+=y;
    cout << n << "\n";

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
