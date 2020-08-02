
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */



void solve() {
    int n,m;
    cin >> n >> m;
    long long a[m];
    long long x = 0;
    for(int i = 0; i <m; i++) {
        cin >> a[i];
        x += a[i];
    }
    if (x < (long long)n || m > n) {
        cout << "-1\n";
        return ;
    }
    long long ans[m];
    long long idx = 0;
    for(int i = 0; i < m;i++) {
        if (idx  + a[i] > n) {
            cout << "-1\n";
            return;
        }
        ans[i] = idx + 1;
        long long d = min(a[i]-1,x - n);
        idx += a[i] - d;
        x -= d;

    }
    if (x > n) {
        cout << "-1\n";
    } else {
        for(int i = 0; i <m; i++) {
            cout << ans[i] << " ";
        } cout << "\n";
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
