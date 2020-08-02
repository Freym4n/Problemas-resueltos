#include <bits/stdc++.h>

using namespace std;

long long const inf = 1e9;

void solve()  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cg = 0;
    vector<int> pre (n), suf (n);
    pre[0] = 1;
    int max_p = 0;
    for(int i = 1; i <n; i++) {
        if (s[i-1] == s[i]) {
            pre[i] = pre[i-1]+1;
        } else {
            pre[i] = 1;
        }
        if (s[i] == 'G')
            max_p = max(max_p,pre[i]);
    }
    suf[n-1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        if(s[i] == s[i+1]) {
            suf[i] = suf[i+1] + 1;
        } else {
            suf[i] = 1;
        }
    }
    for(int i = 0; i <n; i++) {
        if (s[i]== 'G') cg++;
    }
    int best = -1;
    for(int i = 1; i < n-1; i++) {
        if (s[i] == 'S') {
            if (s[i-1] == 'G' && s[i+1] == 'G') {
                if (pre[i-1] + suf[i+1] < cg)
                    best = max(best, pre[i-1] + suf[i+1] + 1);
                else {
                    best = max(best, pre[i-1] + suf[i+1]);
                }
            }
        }
    }
    if (cg > max_p) max_p++;
    cout << max(max_p,best) << "\n";


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin >> t;
    //while(t--) {
        solve();
    //}
}
