#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string ans (n,'9');
    int idx  = n - 1;
    while(n>0 && idx >= 0) {
        ans[idx] = '8';
        idx--;
        n -= 4;
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) solve();
    //solve();
}



