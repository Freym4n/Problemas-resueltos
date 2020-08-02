
#include <bits/stdc++.h>

using namespace std;



void solve() {
    long long a,b;
    cin >> a >> b;
    if (a > b) {
        swap(a,b);
    }
    long long dif = min (b - a, a);
    long long ans = dif;
    b -= dif*2;
    a -= dif;
    long long d = (a/3);
    ans += d*2;
    a = a%3;
    b -= d*3;
    ans += min (b/2, a);
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
