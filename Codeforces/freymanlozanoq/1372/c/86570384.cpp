#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n;
    cin >> n;
    int a[n];
    int cont = 0;
    for(int i = 0; i< n; i++) {
        cin >> a[i];
        if (a[i] == i+1) cont++;
    }
    if (cont == n) {
        cout << "0\n";
        return;
    }
    if (cont == 0) {
        cout << "1\n";
        return;
    }
    bool p = 0;
    int temp = 0;
    for(int i = 0; i <n; i++) {
        if (a[i] !=  i+1) {
            p = true;
            temp++;

        } else if (p) {
            break;
        }
    }
    if (temp == n-cont) {
        cout << "1\n";
        return;
    }
    cout << "2\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    //solve();
}
