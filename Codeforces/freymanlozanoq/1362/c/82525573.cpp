
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */


void solve() {
    long long n;
    cin >> n;
    long long ans = 0,temp;
    for(long long  i = 1 ; n>0; i++) {
        if (n%2 ==1)
            temp = ((n+1)/2);
        else
            temp = (n/2);
        n -= temp;
        ans += temp*i;
    }
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
