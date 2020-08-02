#include <bits/stdc++.h>

using namespace std;


void solve()  {
    int n;
    cin >> n;
    set<int> s;
    int a[n];
    int cont = 0;
    for(int i = 0; i < 2*n; i++) {
        int x; cin >> x;
        if (!s.count(x)) {
            a[cont++] = x;
            s.insert(x);
        }
    }
    for(int i = 0; i <n; i++) {
        cout << a[i] << " ";
    } cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    //solve();

}
