/*
 * Main.cpp
 *
 *  Created on: 26/03/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a (n);
	vector<int> b (n);
	for(int i = 0; i <n; i++) {
		cin >> a[i];
	}
	for( int i = 0; i < n ; i++) {
		cin >> b[i];
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(),b.rend());
	int i = 0,j = 0,res = 0;
	while (i < n) {
		if (a[i] >= b[j]) {
			i++;
		} else {
			i++;
			j++;
			res++;
		}
 	}
	cout << res << "\n";
	return 0;
}

