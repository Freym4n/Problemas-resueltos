
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        int ans = 1000;
        for(int i = 0; i < n; i++) {
            cin >>  a[i];
        }
        sort(a, a + n);
        int cont_even = 0;
        int cont_odd = 0;
        for(int i = 0; i< n; i++) {
            if (a[i] %2 == 0) {
                cont_even ++;
            } else {
                cont_odd ++;
            }
        }
        bool possible = false;
        if (cont_even % 2 == 0) {
            possible = true;
        } else {
            for(int i = 1; i < n; i++) {
                if (abs(a[i]-a[i-1]) == 1) {
                    possible = true;
                }
            }
        }
        cout << (possible?"YES":"NO") << "\n";

    }
}
