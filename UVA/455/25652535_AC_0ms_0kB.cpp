#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool per = true;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            per = true;
            if (n%i != 0) continue;
            for(int j = 0; j < n - i ; j++) {
                if (s[j] != s[j+i]) per = false;
            }
            if (per) {
                 ans = i;
                 break;
            }
        }
        cout << ans << "\n";
        if (t > 0) cout << "\n";
    }
}
