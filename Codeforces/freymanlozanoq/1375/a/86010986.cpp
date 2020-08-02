#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i <n; i++) {
        cin >> a[i];
        if (i%2 == 0) a[i] = -abs(a[i]);
        else a[i] = abs(a[i]);
    }
    for(int i: a) cout << i << " ";
    cout << "\n";

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
