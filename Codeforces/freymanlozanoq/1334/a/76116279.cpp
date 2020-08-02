/*
 * Main.cpp
 *
 *  Created on: 6/04/2020
 *      Author: freyman
 */
#include <bits/stdc++.h>

using namespace std;

int const inf = 1000000002;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int dif,plays,clears;
	while(t--) {
		int n;
		cin >>n ;
		int c[n];
		int p[n];
		for(int i = 0; i <  n; i++) {
			cin >> p[i] >> c[i];
		}
		dif = 0;
		clears = 0;
		plays = 0;
		bool posible = true;
		for(int i = 0; i < n && posible; i++) {
			if (p[i] < plays){
				posible = false;
			}
			if (c[i] < clears){
				posible = false;
			}
			if (p[i] - c[i] < dif || p[i] < c[i]){
				posible = false;
			}
			clears = c[i];
			plays = p[i];
			dif = p[i] - c[i];
		}
		cout << (posible?"YES":"NO") << "\n";
	}

	return 0;
}


