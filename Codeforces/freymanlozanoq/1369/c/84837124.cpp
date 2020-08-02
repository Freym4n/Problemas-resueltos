
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<long long> a (n);
    vector<int> w (k);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> w[i];
    }
    sort(a.rbegin(),a.rend());
    sort(w.begin(), w.end());
    //primero maximos
    int l = 0;
    long long ans = 0;
    for(int i = 0; i < k; i++) {
        if (w[i] == 1) {
            ans += a[l]*2;
            l++;
        } else {
            ans += a[l];
            l++;
        }
        w[i]--;
    }
    //ahora minimos
    for(int i = 0; i < k; i++) {
        if (w[i] == 0) continue;
        for(int j = 0; j < w[i]-1; j++) l++;
        ans += a[l];
        l++;
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

