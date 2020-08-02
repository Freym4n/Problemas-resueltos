#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n;
    cin >> n;
    long long a[n];
    long long even[n],odd[n];
    for(int i = 0; i <n; i++) {
        cin >> a[i];
        if (i%2 == 0 ){
            even[i] = a[i];
            if (i > 0) {
                even[i] += even[i-2];
            }
        } else {
            odd[i] = a[i];
            if (i > 1) {
                odd[i] += odd[i-2];
            }
        }
    }
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }
    long long ans = a[0] + odd[n-2];
    for(int i = 1; i < n; i++) {
        long long temp = 0;
        if (i%2 == 0) {
            temp += even[i];
            temp += odd[n-2] - odd[i-1];
        } else {
            temp += odd[i];
            temp += even[n-1] - even[i-1];
        }
        ans = max(temp,ans);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin >> t;
    //while(t--) {
    //    solve();
    //}

    solve();
}
