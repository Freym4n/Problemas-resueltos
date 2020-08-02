#include <bits/stdc++.h>

using namespace std;

long long const inf = 1e9;

void solve()  {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> lst (m+1);
    vector<int> ans (n+1,0);
    for(int i = 0;i < n; i++) {
        int s,r;
        cin >> s >> r;
        lst[s].push_back(r);
    }
    for(int i = 1; i <= m; i++) {
        sort(lst[i].rbegin(),lst[i].rend());
    }
    for(int i = 1; i <= m; i++) {
        if (!lst[i].empty() && lst[i][0] > 0 ) ans[0] += lst[i][0];
    }
    for(int i = 1; i <= m; i++) {
        int len = lst[i].size();
        for(int j = 1; j < len; j++) {
            lst[i][j] += lst[i][j-1];
            if (lst[i][j] > 0) ans[j] += lst[i][j];
        }
    }
    int best = 0;
    for(int i = 0; i <= n; i++) {
        best = max(best,ans[i]);
    }
    cout << best << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin >> t;
    //while(t--) {
        solve();
    //}
}
