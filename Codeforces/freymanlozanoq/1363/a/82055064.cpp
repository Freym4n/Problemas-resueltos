
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

void solve() {
    int n,x;
    cin >> n >> x;
    int a[n];
    int contp = 0,conti =0 ;
    for(int i = 0; i <n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            contp++;
        } else {
            conti++;
        }
    }
    if (contp == n || (conti == n && (x%2 == 0)) || (x == n && conti%2 == 0)) {
            cout << "No\n";
    } else {
            cout << "Yes\n";
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
