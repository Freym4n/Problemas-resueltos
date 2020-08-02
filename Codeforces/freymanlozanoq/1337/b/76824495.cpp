/*
 * Main.cpp
 *
 *  Created on: 15/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	int limit;
	cin >> t;
	while(t--) {
		int x,n,m;
		cin >> x >> n>>m;
		limit = 10*m;

		while (n-- && x > 20) {
			x = x/2 + 10;
		}

		if (x <= limit) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}


