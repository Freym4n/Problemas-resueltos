
#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n,k,ans;
        cin >> n >> k;
        ans = ((k)/(n-1))*n + (k)%(n-1);
        if (ans%n == 0) ans--;
        cout << ans << "\n";
    }

}
