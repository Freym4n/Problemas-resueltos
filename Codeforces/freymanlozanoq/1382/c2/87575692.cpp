#include <bits/stdc++.h>

using namespace std;


void solve()  {
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> ans;
    //array of ceros

    for(int i = 0; i < n - 1; i++) {
        if (s1[i] != s1[i+1]) ans.push_back(i);
    }
    int last = 0;
    if (s1[n-1] == '1') last = 1;

    for(int i = n-1; i >= 0; i--) {
        if (s2[i] - '0' ==  last) continue;
        ans.push_back(i);
        last ^= 1;
    }
    cout << ans.size() << " ";
    for(int d: ans) cout << (d+1) << " ";
    cout << "\n";





}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; while(t--) solve();
    //solve();

}
