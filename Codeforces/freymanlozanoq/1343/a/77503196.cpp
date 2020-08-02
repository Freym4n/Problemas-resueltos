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
		int div = 2;
		for(int i = 2; i < 30; i++) {
			div = (1<<i)-1;
			if (n%div == 0) {
				cout << n/div << "\n";
				break;
			}
		}
	}


}


