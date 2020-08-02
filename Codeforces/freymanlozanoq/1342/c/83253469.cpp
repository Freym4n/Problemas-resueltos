
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */



void solve() {
    int a,b,q;
    cin >> a >> b >> q;
    long long l,r;
    if (a > b) swap(a,b);
    long long gcd = a*b/(__gcd(a,b));
    for(int rep = 0; rep < q ; rep++) {
        cin >> l >> r;
        if (b%a == 0) {
            cout <<"0\n";
            continue;
        }
        long long temp1 = l/gcd;
        long long first_gcd = (temp1)*gcd;
        l = max(l, first_gcd + b);
        long long temp2 = r/gcd;
        long long last_gcd = gcd*temp2;
        r = max(r, last_gcd + b-1);
        long long equals_mods = ((last_gcd - first_gcd)/gcd);
        long long ans = (r  - l + 1) - equals_mods*b;
        cout << ans;
        if (rep < q - 1) cout << " ";
        else cout << "\n";



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
