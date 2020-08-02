/*
 * Main.cpp
 *
 *  Created on: 13/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {
	if (a == b) return 0;
	if (a > b) {
		if ((a-b)%2 == 0) return 1;
		else return 2;
	} else {
		if ((a-b)%2 == 0) return 2;
		else return 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a,b;
		cin >>a >> b;
		cout << solve(a,b) << "\n";
	}


	return 0;
}


