#include <bits/stdc++.h>

using namespace std;

int n,m;

bool is_ok(int i, int j) {
    return i  < n && j < m && i >= 0 && j >= 0;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    if (a[0] > a[n-1]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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
