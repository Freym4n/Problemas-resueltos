#include <bits/stdc++.h>

using namespace std;



void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> f(10,0);
    int ans = n-2;
    for(int i = 0; i < n; i++) {
        f[s[i]-'0']++;
        ans = min(ans, n - f[s[i]-'0']);
    }
    int l = -1,temp;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(i == j) continue;
            temp = 0;
            for(int idx = 0; idx < n; idx++) {
                if (s[idx] - '0' != j && s[idx] - '0' != i) continue;
                if (s[idx] != l)  {
                    temp++;
                    l = s[idx];
                }
            }
            temp = (temp & (~1));
            ans = min(ans, n - temp);
        }
    }
    cout << ans << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) solve();
    //solve();

}
