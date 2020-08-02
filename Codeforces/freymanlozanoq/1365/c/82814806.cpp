
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

void solve() {
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for( int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> cont(n+1);
    int pos[n+1];
    for(int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        int d = (pos[b[i]] + n - i)%n;
        cont[d] ++;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = max(ans,cont[i]);
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
