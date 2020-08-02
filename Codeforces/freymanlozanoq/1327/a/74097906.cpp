#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; long long n,k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		if ((n - (k*k))%2 == 0 &&  (k*k) <= n) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}

	}

	return 0;
}
