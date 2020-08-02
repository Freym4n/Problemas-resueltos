#include <bits/stdc++.h>

using namespace std;

long long const m =  1e9 + 7;

void solve() {
    int x;
    cin >> x;
    string s;
    cin >> s;
    int len = s.size();
    vector<long long> p(max(len,x+1));
    for(int i = 0; i < len; i++) {
        p[i] = s[i] - '0';
    }
    int idx = len;
    for(int l = 0; l <= x && idx <= x; l++) {
        if (p[l] == 1) continue;
        int last_len = idx;
        for(int r = 0; r < p[l]-1 && idx <= x; r++) {
            for(int i = l + 1; i < last_len && idx <= x; i++) {
                p[idx++] = p[i];
            }
        }
    }
    long long ans = len;
    for(int i = 0; i < x; i++) {
        ans = (ans + ((p[i]-1)*((ans-(i+1) + m)%m))%m)%m;
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
