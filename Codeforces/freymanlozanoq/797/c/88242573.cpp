#include <bits/stdc++.h>

using namespace std;



void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int,int>> suf (n);
    suf[n-1] = {s[n-1],n-1};
    for(int i = n - 2; i >= 0; i--) {
        if (s[i] <= suf[i+1].first) {
            suf[i] = {s[i],i};
        } else {
            suf[i] = suf[i+1];
        }
    }
    string z,t;
    for(int i = 0; i < n; i++) {
        while(!z.empty() && z.back() <= suf[i].first) {
            t.push_back(z.back());
            z.pop_back();
        }
        int l = suf[i].second;
        for(int j = i; j < l; j++) {
            z.push_back(s[j]);
        }
        t.push_back(s[l]);
        i = l;
    }
    while(!z.empty()) {
        t.push_back(z.back()); z.pop_back();
    }
    cout << t << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    //cin >> t; while(t--) solve();
    solve();

}
