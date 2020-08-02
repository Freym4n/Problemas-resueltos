#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<long long> dp(11,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < 11; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    int n;
    int p = false;
    while(cin >> n) {
        if(!p) p = true;
        else cout << "\n";
        cout << dp[n] << "\n";
    }




}
