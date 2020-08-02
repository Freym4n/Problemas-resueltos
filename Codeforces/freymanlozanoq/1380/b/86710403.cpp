#include <bits/stdc++.h>

using namespace std;



void solve()  {
    string s;
    cin  >> s;
    int n = s.size();
    string ans;
    vector<int> f(3,0);
    for(int i = 0; i < n; i++) {
        if (s[i] == 'R') f[0]++;
        else if (s[i] ==  'S') f[1]++;
        else f[2]++;
    }
    if (f[0] >= f[1] && f[0] >= f[2]) {
        ans = string(n,'P');
    } else if (f[1] >= f[0] && f[1] >= f[2]) {
        ans  = string(n,'R');
    } else {
        ans  = string(n,'S');
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

    //solve();
}
