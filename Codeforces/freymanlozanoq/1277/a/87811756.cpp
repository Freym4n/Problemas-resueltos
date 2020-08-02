#include <bits/stdc++.h>

using namespace std;



void solve(vector<long long> &pow)  {
    long long n;
    cin >> n;
    long long d  = log10(n);
    long long ans  = d*9;
    long long x  = pow[d];
    for(long long i = x; i <= n; i += x) {
        ans++;
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> pow (10,1);
    for(int i = 1; i < 10; i++) {
        pow[i] = pow[i-1]*10 + 1;
    }
    int t;
    cin >> t; while(t--) solve(pow);
    //solve();

}
