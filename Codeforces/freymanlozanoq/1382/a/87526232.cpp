#include <bits/stdc++.h>

using namespace std;


void solve()  {
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    set<int> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < m; i++) {
        if (s.count(b[i])) {
            cout << "YES\n";
            cout << "1 " << b[i] << "\n";
            return;
        }
    }
    cout << "NO\n";



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; while(t--) solve();
    //solve();

}
