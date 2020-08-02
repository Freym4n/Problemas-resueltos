
#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    int first, second, remainder;
    first  = min (n/k,m);
    remainder = max(0, m - first);
    second = remainder/(k-1);
    if (remainder%(k-1) != 0) {
        second++;

    }
    cout << (first-second) << "\n";
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
