
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k;
        long long ans = 1;
        if (k >= n) {
            cout << "1\n";
            continue;
        }
        for(long long i = 2; i <= sqrt(n); i++) {
            if (n % i  == 0) {
                if (i <= k) {
                    ans = max(ans,i);
                }
                if (n/i <= k) {
                    ans = max(ans,n/i);
                }
            }
        }
        cout << n/ans << "\n";

    }
}
