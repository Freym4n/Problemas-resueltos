#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n;
    cin >> n;
    vector<string> s;
    string num = to_string(n);
    int m1  = num.size();
    for(int i = 1; i*i <= n; i++) {
        s.push_back(to_string(i*i));
    }
    int len = s.size();
    for(int i = len-1; i >= 0; i--) {
        int m = s[i].size();
        int cont = 0;
        for(int j = 0; j < m1 && cont < m; j++) {
            if (s[i][cont] == num[j]) cont++;
        }
        if (cont == m) {
            cout << (abs(m-m1)) << "\n";
            return;
        }
    }
    cout << "-1\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //cin >> t;
    //while(t--) {
        solve();
    //}
}
