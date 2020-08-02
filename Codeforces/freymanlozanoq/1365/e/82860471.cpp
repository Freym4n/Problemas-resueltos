
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */



void solve() {
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> s[n];
    long long dp[n];
    for(int i = 0; i <n; i++) {
        dp[i] = a[i];
        s[i].insert(i);
    }
    for(int rep = 1; rep < min(3,n) ; rep++) {
        for(int i = 0; i < n; i++) {
            long long maximo = 0;
            int idx = 0;
            for(int j = 0; j < n; j++) {
                if (s[i].count(j)) continue;
                if (maximo < (dp[i]|a[j])) {
                    maximo = (dp[i]|a[j]);
                    idx = j;
                }
            }
            s[i].insert(idx);
            dp[i] = maximo;
        }
    }
    long long ans = 0;
    for(int i = 0; i <n; i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
