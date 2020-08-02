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
		if (n%4 != 0) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		long long res = 0;
		for(int i = 0; i < n/2; i++) {
			cout << (i*2+2) << " ";
			res += (i*2)+2;
		}
		long long odd = 1;
		for(int i = n/2; i < n - 1; i++) {
			cout << odd << " ";
			res -= odd;
			odd+=2;

		}
		cout << res << "\n";
	}


}


