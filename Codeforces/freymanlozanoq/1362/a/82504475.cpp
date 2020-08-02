
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */


void solve() {
    long long a,b;
    cin >> a >> b;
    if (a < b) swap(a,b);
    if (a % b != 0 ) {
        cout << "-1\n";
        return;
    }
    long long div = a/b;
    if ((div&(div-1)) != 0) {
        cout << "-1\n";
        return;
    }
    long long ans = 0;
    while(div%8 == 0) {
        ans++;
        div/=8;
    }
    while(div%4 == 0) {
        ans++;
        div/=4;
    }
    while(div%2 == 0) {
        ans++;
        div/=2;
    }
    cout << ans << "\n";
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
