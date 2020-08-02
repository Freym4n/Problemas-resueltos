
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cont = 0;
    for(int j = 0; j < n; j++) {
        cin >> b[j];
        if (b[j] == 0) cont++;
    }
    if (cont < n && cont > 0) {
        cout << "Yes\n";
        return;
    }
    bool isSorted = true;
    for(int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) isSorted = false;
    }
    cout << (isSorted?"Yes\n":"No\n");


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
