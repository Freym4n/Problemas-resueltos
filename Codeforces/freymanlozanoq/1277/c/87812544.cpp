#include <bits/stdc++.h>

using namespace std;



void solve()  {
    string s;
    cin >> s;
    string t = "two", o = "one", to = "twone";
    int cont1,cont2,cont3;
    vector<int> ans;
    int n = s.size();
    for (int i = 0; i < n - 2; i++) {
        cont1 = 0;
        cont2 = 0;
        cont3 = 0;
        for (int j = 0; j < 3; j++) {
            if (o[j] != s[i+j]) break;
            cont1++;
        }
        for (int j = 0; j < 3; j++) {
            if (t[j] != s[i+j]) break;
            cont2++;
        }
        for (int j = 0; j < 5 && i < n - 4; j++) {
            if (to[j] != s[i+j]) break;
            cont3++;
        }
        if (cont3 == 5) {
            ans.push_back(i + 2);
            s[i+2] = '$';
        } else if (cont2 == 3 || cont1 == 3) {
            ans.push_back(i+1);
            s[i+1] = '$';
        }
    }
    cout << ans.size() << "\n";
    for(int d: ans) cout << d+1 << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; while(t--) solve();
    //solve();

}
