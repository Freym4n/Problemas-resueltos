
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int x,y,n;
    cin >> x >> y >> n;
    vector<string> ans (n);
    for(int i= 1; i <= n; i++) {
        if (i%x == 0) {
            ans[i-1] = "Fizz";
        }
        if (i%y == 0) {
            ans[i-1] += "Buzz";
        }
    }
    for(int i = 0; i < n; i++) {
        if (!ans[i].empty())
            cout << ans[i] << "\n";
        else
            cout << (i+1) << "\n";
    }





}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--) {
        solve();
    }
}
