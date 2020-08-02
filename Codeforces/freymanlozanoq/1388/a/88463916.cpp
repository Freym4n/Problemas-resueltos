#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n <= 30) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (n - 30 == 6 || n - 30 == 10 || n - 30 == 14) {
        cout << "15 10 6 " << (n-31) << '\n';
    }
    else {
        cout << "14 10 6 " << (n-30) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) solve();
    //solve();
}



