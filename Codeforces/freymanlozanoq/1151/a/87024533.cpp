#include <bits/stdc++.h>

using namespace std;




void solve()  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 200;
    for(int i = 3;i < n; i++) {
        int temp = 0;
        temp += min((s[i-3] + 26 - 'A')%26,('A'  + 26 - s[i-3])%26);
        temp += min((s[i-2] + 26 - 'C')%26,('C'  + 26 - s[i-2])%26)%26;
        temp += min((s[i-1] + 26 - 'T')%26,('T'  + 26 - s[i-1])%26);
        temp += min((s[i] + 26 - 'G')%26,('G'  + 26 - s[i])%26);
        ans = min(ans,temp);
    } cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //cin >> t;
    //while(t--) solve();
    solve();

}
