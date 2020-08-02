
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    string last, pass;
    cin >> last >> pass;
    string ans;
    for(int i = 0; i < m - n; i++) {
        ans.push_back('$');
    }
    ans += last;
    for(int i = m - n - 1; i >=0; i--) {
        ans[i] = (pass[i + n] - ans[i + n] + 26)%26 + 'a';
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();

}
