#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void solve() {
    ll r,b,k;
    cin >> r >> b >> k;
    if (b > r) swap(r,b);
    ll gcd = __gcd(r,b);
    r /= gcd;
    b /= gcd;
    if ((k - 1)*b + 1 < r) {
        cout << "REBEL\n";
    } else {
        cout << "OBEY\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) solve();
    //solve();
}
