#include <bits/stdc++.h>

using namespace std;



void solve() {
   long long n;
   cin >> n;
   n>>=1;
   long long ans = 8*((n*(n+1)*(2*n + 1))/6);
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
