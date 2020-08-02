#include <bits/stdc++.h>

using namespace std;

int n;
int const inf = 1e9;
//minima diferencia entre l1 y l2



void solve()  {
    cin >> n;
    int p[n*2];
    for(int i = 0; i < 2*n; i++) {
        cin >> p[i];
    }
    int pre[2*n];
    pre[0] = 1;
    int last = p[0];
    for(int i = 1; i  <  2*n; i++) {
        if  (last > p[i]) pre[i] = pre[i-1] + 1;
        else {
            pre[i] = 1;
            last = p[i];
        }

    }
    vector<int> seg;

    for(int i = 0; i < n*2;i++) {
        if (i == 2*n-1 || pre[i+1] <= pre[i]) seg.push_back(pre[i]);
    }int m = seg.size();
    bool dp[m+1][n*2];
    memset(dp,false,sizeof dp);
    dp[0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 2*n; j++) {
            if (!dp[i][j]) continue;
            dp[i+1][j] = 1;
            dp[i+1][j+seg[i]] = 1;
        }
    }
    if (dp[m][n]) cout << "YES\n";
    else cout << "NO\n";







}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; while(t--) solve();
    //solve();

}
