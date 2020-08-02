#include <bits/stdc++.h>

using namespace std;


void solve()  {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 1) a[i] = 2;
        if(i == n-1) a[i] = 1;
    }
    int w = 0;
    for(int i = n-2; i >= 0; i--) {
        if (a[i] == 1) w^=1;
        else {
            if (w == 1) w = 0;
        }
    }
    cout << (w?"Second":"First") << "\n";





}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; while(t--) solve();
    //solve();

}
