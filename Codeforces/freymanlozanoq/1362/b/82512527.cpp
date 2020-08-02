
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */


void solve() {
    int n;
    cin >> n;
    int s[n];
    vector<int> f(1025,0);
    int cont = 0;
    for(int i =0 ; i< n; i++) {
        cin >> s[i];
        f[s[i]] ++;
    }
    for(int i = 1; i <= 1024; i++) {
        cont = 0;
        for(int j = 0; j < n; j++) {
            int r = (s[j]^i);
            if (r > 1024) break;
            if (f[r] == 1) cont++;
        }
        if (cont == n) {
            cout << (i) << "\n";
            return;
        }
    }
    cout << "-1\n";

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
