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
        int cont = 0;
        int l = 0, r = 0;
        vector<int> v(3,0);
        int ans = n;
        bool possible = false;
        while (r <= n) {
            if (cont < 3 && r < n) {
                int idx = s[r] - '0';
                if (v[idx-1] == 0) {
                    cont ++;
                } v[idx-1]++;
                r++;
            } else {
                if (cont == 3) {
                    ans = min(ans, r - l);
                    possible = true;
                }
                int idx = s[l] - '0';
                if (v[idx-1] == 1) {
                    cont --;
                } v[idx-1]--;
                l++;
                r = max(l,r);
            }
        }
        if (!possible) {
            cout << "0\n";
        } else {
            cout << ans << "\n";
        }



    }
}
