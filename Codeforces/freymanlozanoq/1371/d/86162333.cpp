#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,k;
    cin >> n >> k;
    int a[n][n];
    memset(a,0, sizeof a);
    vector<vector<pair<int,int>>> d (301);
    for(int i = 0; i <n; i++) {
        for(int j = 0; j <n; j++) {
            d[(i+j)%n].push_back({i,j});
        }
    }
    int rep = 0;
    vector<int> cont_r(n,0);
    vector<int> cont_c(n,0);

    for(int i = 0; i < n && rep < k; i++) {
        for(int j = 0; j < n && rep < k; j++) {
            rep++;
            int x = d[i][j].first;
            int y = d[i][j].second;
            a[x][y]=1;
            cont_c[y]++;
            cont_r[x]++;
        }
    }
    int min_r = n,max_r = 0,min_c = n,max_c = 0;
    for(int i = 0; i <n; i++) {
        max_c = max(max_c,cont_c[i]);
        min_c = min(min_c,cont_c[i]);
        max_r = max(max_r,cont_r[i]);
        min_r = min(min_r,cont_r[i]);
    }
    long long f = (max_r-min_r)*(max_r-min_r) + (max_c-min_c)*(max_c-min_c);
    cout << f << "\n";
    for(int i = 0; i <n; i++) {
        for(int j = 0; j <n; j++) {
            cout << a[i][j];
        } cout << "\n";
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
