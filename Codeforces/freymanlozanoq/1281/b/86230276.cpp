#include <bits/stdc++.h>

using namespace std;



void solve() {
    string s,c;
    cin >> s >> c;
    int n = s.size();
    int n1 = c.size();
    for(int i = 0; i < n-1; i++) {
        int idx = -1, val = 250;
        for(int j = i + 1; j< n; j++) {
            int temp = s[j] - 'A';
            if (temp <= val) {
                val = temp;
                idx = j;
            }
        }
        if (val < s[i] - 'A') {
            char t = s[i];
            s[i] = s[idx];
            s[idx] = t;
            break;
        }
    }
    if (s.compare(c) >= 0) {
        cout << "---\n";
    } else {
        cout << s << "\n";
    }
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
