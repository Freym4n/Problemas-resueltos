
#include <bits/stdc++.h>

using namespace std;

int const MAX_N = 2e6+1;
long long d[MAX_N];
long long p[MAX_N];
long long h[MAX_N];
long long mod = 1e9 + 7;
void solve() {
    long long n;
    cin >> n;
    cout << (d[n-1]*4)%mod << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    d[0] = 0; d[1] = 0; d[2] = 1;
    p[0] = 0; p[1] = 1; p[2] = 1;
    h[0] = 1; h[1] = 1; h[2] = 3;
    for(int i = 3; i < MAX_N; i++) {
        d[i] = (p[i-1] + d[i-3])%mod;
        p[i] = h[i-1];
        h[i] = (p[i-1]*2 + h[i-1])%mod;
    }
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}

