#include <bits/stdc++.h>

using namespace std;

void solve() {
    double a,b,c;
    cin >> a >> b >> c;
    long long a1,a2;
    if(a < c) {
        a1 = 1;
    } else {
        a1 = -1;
    }
    double unit = c/b;
    if (unit < a) {
        a2 = b;
    } else {
        a2 = -1;
    }
    cout << a1 << " " << a2 << "\n";

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
