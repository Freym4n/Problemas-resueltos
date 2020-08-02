#include <bits/stdc++.h>

using namespace std;



void solve() {
    long long l,r;
    cin >> l >> r;
    if (l*2 > r) {
        cout << "-1 -1\n";
        return;
    }
    cout << l <<  ' '  << l*2 << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) solve();
    //solve();

}
