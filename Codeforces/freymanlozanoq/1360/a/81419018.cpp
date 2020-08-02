
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        int ans = min(a,b);
        ans *= 2;
        ans*=ans;
        ans = max(ans, max(a,b)*max(a,b));
        cout << ans << "\n";
    }
}
