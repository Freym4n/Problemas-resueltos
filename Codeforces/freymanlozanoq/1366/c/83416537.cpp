
#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i< n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int len = (n + m + 1)/2;
    int dist[len][2];
    memset(dist,0,sizeof(dist));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int d = min(i + j + 1, (n-i) + (m-j) - 1);
            if (d >= len) continue;
            if (a[i][j] == 1) dist[d][0] ++;
            else dist[d][1] ++;
        }
    }
    int ans = 0;
    for(int i = 1; i < len; i++) {
        int total = dist[i][0] + dist[i][1];
        ans += min(total-  dist[i][0], total - dist[i][1]);
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
