
#include <bits/stdc++.h>

using namespace std;
int const mod = 1000000007;
long long n,m;

long long f(int i) {
    long long ans = 0;
    long long x;
    for(int j = 1; j <= i; j++) {
        x = j*(j+1)/2;
        ans = (ans + x)%mod;
    }
    return ans;
}

long long solve() {
    long long dp[n];
    for(int i = 0; i < n; i++) dp[i] = 1;
    for(int i = 1; i < m; i++) {
        for(int j = 1; j <  n; j++) {
            dp[j] = (dp[j] + dp[j-1])%mod;
        }
    }
    long long ans = 0,x;
    for(int i = 0; i < n; i++) {
        x = 0;
        for(int j = 0; j <= n-i-1; j++) {
            x = (x + dp[j])%mod;
        }

        x = (x*dp[i])%mod;
        ans = (ans  + x)%mod;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
    long long result = solve();
    cout << result << "\n";

	return 0;

}
