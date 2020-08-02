#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    if (n < 10) {
        cout << "0 0 0\n";
        return;
    }
    int ls = 0;
    for(int i = (n-2)/2; i >= 0; i--) {
        if (a[i] != a[i+1]) {
            ls = i;
            break;
        }
    }
    if (ls == 0) {
        cout << "0 0 0\n";
        return;
    }
    int li = -1;
    for(int i = 0; i <ls;i++) {
        if (a[i] != a[i+1]) {
            li = i;
            break;
        }
    }
    if (li == -1 || ls - li < (li+2)*2) {
        cout << "0 0 0\n";
        return;
    }
    int lm = 0;
    for(int i = (li+1)*2; i < ls-li-1; i++) {
        if (a[i] != a[i+1]) {
            lm = i;
            break;
        }
    }
    if (lm == 0) {
        cout << "0 0 0\n";
        return;
    }
    cout << li + 1<< " " << lm -li << " " << ls-lm << "\n";
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
