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
		int n,m;
		cin >> n >> m;
		int a[n];
		for(int i = 0; i <n; i++) {
			cin >> a[i];
		}
		int p[m];
		for(int i = 0; i < m; i++) {
			cin >> p[i];
			p[i]--;
		}

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++){
				if (a[p[j]] > a[p[j]+1]){
					swap(a[p[j]],a[p[j]+1]);
				}
			}
		}
		bool posible = true;
		for(int i = 1; i < n; i++) {
			if (a[i] < a[i-1]) posible = false;
		}

		cout << (posible?"YES":"NO") << "\n";
	}



	return 0;
}


