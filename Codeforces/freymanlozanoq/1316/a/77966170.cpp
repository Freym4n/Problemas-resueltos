/*
 * Main.cpp
 *
 *  Created on: 24/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int const inf = 1000000001;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		int a[n];
		int sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			sum+= a[i];
		}
		cout << min(m,sum) << "\n";
	}
}


