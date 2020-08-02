#include <bits/stdc++.h>

using namespace std;



void solve()  {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << "a\n";
        return;
    }
    for(int i = 0; i <n; i++) {
        if (s[i] != '?') continue;
        vector<bool> v (3,1);
        if (i > 0)
            v[s[i-1]-'a'] = 0;
        if (i < n - 1 && s[i+1] != '?')
            v[s[i+1] - 'a'] = 0;
        for(int j = 0; j < 3; j++)
            if (v[j]) {
                s[i] = j + 'a';
                break;
            }
    }

    for(int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            cout << "-1\n";
            return;
        }
    }
    cout << s << "\n";
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
