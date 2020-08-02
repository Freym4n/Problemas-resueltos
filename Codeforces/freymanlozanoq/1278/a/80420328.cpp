#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> a, vector<int> b) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    } return true;
}

void solve() {
    string s1,s2;
    cin >> s1 >> s2;
    int len,n;
    len = s1.size();
    n = s2.size();
    if (n < len)  {
        cout << "NO\n";
        return;
    }
    vector<int > origin (27);
    for(int i = 0;i < len; i++) {
        int idx = s1[i]- 'a';
        origin[idx] ++;
    }
    vector<int> current (27);
    for(int i = 0; i < len; i++) {
        int idx = s2[i] - 'a';
        current[idx] ++;
    }
    if (check(current,origin)) {
        cout << "YES\n";
        return;
    }
    for(int i = 1; i < n - len +1; i++) {
        int last = s2[i-1] - 'a';
        int next = s2[i + len-1] - 'a';
        current[last]--;
        current[next]++;
        if (check(current,origin)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
