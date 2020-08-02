
#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,m, x,y;
    cin >> n >> m >> x >> y;
    int a[n][m];
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if (s[j] == '.') {
                a[i][j] = 1;
            } else {
                a[i][j] = 2;
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i <n; i++) {
        int cont =0 ;
        for(int j = 0; j< m; j++) {
            if (a[i][j] == 1) {
                cont++;
                if (cont == 2 && x*2 >= y) {
                    ans -= x;
                    ans += y;
                    cont =0 ;
                } else {
                    ans += x;
                }
            } else {
                cont = 0;
            }
        }
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
