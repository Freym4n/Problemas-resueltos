
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> uno (n,0);
    vector<int> cero (n,0);
    for(int i = 0; i <n; i++) {
        if (s[i] == '1') {
            uno[i]++;
        } else {
            cero[i]++;
        }
        if (i > 0) {
            cero[i] += cero[i-1];
            uno[i] += uno[i-1];
        }
    }
    int unos = uno[n-1];
    int ceros = cero[n-1];
    if (unos == n || ceros == n) {
        cout << "0\n";
        return;
    }
    int ans  = min(n-unos,n-ceros);
    for(int i = 0; i < n; i++) {
        int moves = ((i+1)-cero[i])+(ceros-cero[i]);
        ans = min(ans,moves);
        moves = ((i+1)-uno[i]) + (unos - uno[i]);
        ans = min(ans,moves);
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
