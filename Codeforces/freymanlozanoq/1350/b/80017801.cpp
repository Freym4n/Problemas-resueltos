#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 1;
        vector<int> dp (n,0);
        for(int i = n - 1; i >= 0; i--) {
            int x = 0;
            for(int j = (i+i + 1); j < n; j +=(i+1)) {
                if (a[i] >= a[j]) continue;
                x = max(x,dp[j]);
            }
            dp[i] = 1 + x;
            ans = max (ans, dp[i]);
        }
        cout << ans << "\n";
    }
}
