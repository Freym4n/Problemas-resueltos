#include <bits/stdc++.h>

using namespace std;

long long const mod = 998244353;

void solve()  {
    int n,k;
    cin >> n >> k;
    vector<int> seg;
    long long sum = 0;
    long long x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if (x > n - k) {
            seg.push_back(i);
            sum += x;
        }
    }
    long long ans = 1;
    for(int i = 0; i < k -1 ; i++) {
        ans = (ans * (seg[i+1]-seg[i]))%mod;
    }
    cout << sum << " "<< ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //cin >> t; while(t--) solve();
    solve();

}
