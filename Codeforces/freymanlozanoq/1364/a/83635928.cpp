
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,x;
    cin >> n >> x;
    int a[n];
    int sum[n];
    for(int i =0 ; i <n; i++){
        cin >> a[i];
    }
    sum[0] = a[0];
    for(int i = 1; i <n; i++){
        sum[i]= a[i] + sum[i-1];
    }
    int last = n + 1;
    for(int i = 0; i<  n; i++){
        if (sum[i]%x == 0) continue;
        last = i;
        break;
    }

    int ans = -1;
    for(int i = 0; i <n; i++){
        if (sum[i]%x == 0) {
            if (i < last) continue;
            ans = max (ans, i - last);
        }
        else {
            ans = max(ans, i+1);
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
