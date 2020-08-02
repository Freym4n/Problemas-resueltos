
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int left = 0;
    string ans;
    while(left < n && s[left] == '0') {
        ans.push_back(s[left]);
        left++;
    }
    string sup;
    int high = n - 1;
    while(high >= 0 && s[high] == '1') {
        sup.push_back('1');
        high--;
    }
    if (high - left > 0) {
        ans.push_back('0');
    }
    ans += sup;
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

