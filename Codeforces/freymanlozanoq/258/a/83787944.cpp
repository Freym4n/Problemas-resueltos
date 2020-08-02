
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    string ans;
    int n = s.size();
    bool deleted = false;
    for(int i =0 ; i < n; i++) {
        if (s[i] == '0' && !deleted) {
            deleted = true;
            continue;
        }
        ans.push_back(s[i]);
    }
    if(!deleted) {
        ans.pop_back();
    }
    cout << ans << "\n";
}
