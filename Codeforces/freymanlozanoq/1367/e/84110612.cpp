
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ml = 0;
    vector<int> fl (26,0);
    for(int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        fl[idx] ++;
        ml = max(fl[idx],ml);
    }
    vector<int> freq(ml+1,0);
    for(int i = 0; i < 26; i++) {
        for(int j = 1; j <= fl[i]; j++) {
                freq[j] += fl[i]/j;
        }
    }
    int ans = 0;
    for(int i = 1; i < ml + 1; i++) {
        int len = freq[i];
        for(int j = 1; j <= len; j++) {
            if (k%j == 0) {
                ans = max(ans, j*i);
            }
        }
    }
    cout << ans<< "\n";




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

