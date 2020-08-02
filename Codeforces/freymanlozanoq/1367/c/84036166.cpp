
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n,k; string s;
    cin >> n >> k;
    cin >> s;
    vector<bool> free (n, false);
    int cont = 1;
    for(int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cont = k+1;
        } else {
            cont--;
            if (cont <= 0) {
                free[i] = true;
                cont = k+1;
            }
        }
    }
    cont = 1;
    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
        if (s[i] == '1') {
            cont = k+1;
        } else {
            cont--;
            if (cont <= 0 && free[i]) {
                ans++;
                cont = k+1;
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

