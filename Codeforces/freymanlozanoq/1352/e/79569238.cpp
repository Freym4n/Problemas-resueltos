#include <bits/stdc++.h>

using namespace std;

int const MAX = 8000;
int a[MAX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t,n,ans,l,r,sum;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ans = 0;
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        for(int j = 0 ; j < n; j++) {
            l = 0;
            r = 1;
            sum = a[0];
            while (r < n) {
                if (sum + a[r] <= a[j]) {
                    sum += a[r];
                    r++;
                } else {
                    if (sum > 0) sum -= a[l];
                    l++;
                }
                if (sum == a[j] && r - l>= 2) {
                    ans ++;
                    break;
                }
                r = max(r,l);
            }
        }
        cout << ans << "\n";


    }

}
