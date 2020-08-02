#include <bits/stdc++.h>

using namespace std;

long long const inf = 1e9;

void solve()  {
    int n; long long x;
    cin >> n >> x;
    long long a[n];
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    vector<int> value (n,0), min_value(n);
    for(int i = n -1 ; i >= 0; i--) {
        if (a[i]*(n-i) < x) value[i] = inf;
        else {
            value[i] = (x + a[i]-1)/a[i] + i;
        }
    }
    min_value[n-1] = value[n-1];
    for(int i = n -2 ; i >= 0; i--) {
        if (value[i] > min_value[i+1]) {
            min_value[i] = min_value[i+1];
        } else {
            min_value[i] = value[i];
        }
    }
    int ans = 0;
    int idx  = min_value[0];
    while (idx < n) {
        ans ++;
        idx = min_value[idx];
    }
    if (idx == n) ans++;

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

    //solve();
}
