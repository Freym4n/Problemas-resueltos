
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    int a[n];
    int contp = 0, conti= 0;
    for(int i = 0; i <n; i++) {
        cin >> a[i];
        if ((a[i]&1)) conti++;
        else contp++;
    }
    if ((n&1) &&  contp != conti + 1) {
        cout << "-1\n";
        return;
    }
    if (!(n&1) && contp != conti) {
        cout << "-1\n";
        return;
    }
    int cont = 0;
    for(int i = 0; i <n; i++) {
        if ((a[i]&1) == (i&1)) continue;
        cont++;
    }
    int ans = (cont + 1)/2;
    cout << ans << "\n";

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

