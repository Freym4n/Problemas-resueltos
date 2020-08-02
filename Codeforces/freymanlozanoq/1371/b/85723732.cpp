#include <bits/stdc++.h>

using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n,r;
        cin >> n >> r;
        long long m = min(n,r);
        if (n > r) {
            m = m*(m+1)/2;
        } else {
            m = m*(m-1)/2 + 1;
        }
        cout << m << "\n";
    }

}
