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
	int n; long long a,b,k;
	cin >> n >> a >> b >> k;
	long long h[n];
	long long hits[n];
	for(int i = 0; i < n; i++) {
		cin >> h[i];
		long long x = h[i]%(a+b);
		if (x == 0) {
			hits[i] = (int) ceil(b*1.0/a);
		} else if (x >0 && x  <= a) {
			hits[i] = 0;
		} else {
			x -= a;
			hits[i] = (int) ceil(x*1.0/a);
		}
	}
	sort(hits,hits+n);
	int ans = 0;
	for(int i = 0; i < n && k > 0; i++) {
		if (hits[i] <= k) {
			k -= hits[i];
			ans++;
		}
	}
	cout << ans << "\n";


}


