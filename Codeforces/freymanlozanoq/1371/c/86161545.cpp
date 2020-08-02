#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a,b,n,m;
    cin >> a >> b >> n >> m;
    if (a + b < n + m) {
        cout << "No\n";
        return;
    }
    if (min(a,b) < m) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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
