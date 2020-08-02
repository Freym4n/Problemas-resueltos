/*
 * Main.cpp
 *
 *  Created on: 17/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int const inf = 1000000001;

int idx[31];
int cont[31];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long long a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}

		long long ans = 0;
		bool p = (a[0]>0?true:false);

		long long best_option = -inf;
		for(int i = 0; i < n; i++) {
			if (p && a[i] < 0) {
				ans += best_option;
				p = false;
				best_option = a[i];
			} else if (p && a[i] > 0) {
				best_option = max (best_option, a[i]);
			} else if (!p && a[i] > 0) {
				ans += best_option;
				p = true;
				best_option = a[i];
			} else {
				best_option = max(best_option, a[i]);
			}
		}
		ans += best_option;
		cout << ans << "\n";
	}


}


