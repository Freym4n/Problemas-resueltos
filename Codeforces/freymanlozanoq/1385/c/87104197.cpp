#include <bits/stdc++.h>

using namespace std;


void solve()  {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    int i  = n - 1;
    while(i > 0 && a[i-1] >= a[i]) i--;
    while( i > 0 && a[i-1] <= a[i]) i--;
    cout << i << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    //solve();

}
