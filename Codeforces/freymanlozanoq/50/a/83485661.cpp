
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    int ans = n * (m/2) + (m%2)*(n/2);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();

}
