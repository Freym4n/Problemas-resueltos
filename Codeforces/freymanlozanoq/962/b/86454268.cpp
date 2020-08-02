#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cont = 0;
    int last = 0;
    for(int i= 0; i <n; i++) {
        if (s[i] == '*') {
            last  = 0;
        } else {
            if (last == 0) {
                if (a > b && a > 0) {
                    a--;
                    cont++;
                    last = 1;
                } else if (b>0) {
                    b--;
                    cont++;
                    last = 2;
                }
            } else if (last == 1) {
                if (b > 0) {
                    b--;
                    cont++;
                    last = 2;
                } else {
                    last = 0;
                }
            } else {
                if (a > 0) {
                    a--;
                    cont++;
                    last = 1;
                } else {
                    last = 0;
                }
            }
        }
    }
    cout << cont << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //cin >> t;
    //while(t--) {
        solve();
    //}
}
