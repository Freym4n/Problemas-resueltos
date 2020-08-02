#include <bits/stdc++.h>

using namespace std;
int const N = 100001;
int const MAX_Z = 6;
int dp[N][MAX_Z][2];
int a[N];
int K,Z;

int rec(int k, int z, bool left) {
    if(k == K) return 0;
    int &r = dp[k][z][left];
    if (r != -1) return r;
    int idx  = k - 2*z;
    if (left || z == Z || idx  == 0) return r = a[idx] + rec(k+1,z,false);
    return r = a[idx] + max(rec(k+1,z,false), rec(k+1,z+1,true));
}


void solve() {
    int n;
    cin >> n >> K >> Z;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= Z; j++) {
            for(int j1 = 0; j1 < 2; j1++) {
                dp[i][j][j1] = -1;
            }

        }
    }
    K++;
    int ans = rec(0,0,false);
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) solve();
    //solve();

}
