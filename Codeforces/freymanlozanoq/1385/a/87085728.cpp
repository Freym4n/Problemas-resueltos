#include <bits/stdc++.h>

using namespace std;


void solve()  {
    vector<int> x(3);
    cin >> x[0] >> x[1] >> x[2];
    sort(x.rbegin(),x.rend());
    if (x[0] == x[1]) {
        cout << "YES\n";
        cout << x[0] << " " << x[2] << " " << x[2] << "\n";
    } else {
        cout << "NO\n";
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    //solve();

}
