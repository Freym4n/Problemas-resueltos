/*
 * Main.cpp
 *
 *  Created on: 23/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int const inf = 1000000001;

int n;

int pos[100001];
int per[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	bool posible;
	while(t--) {
		posible = true;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			pos[a[i]] = i;
			per[i] = 0;
		}
		int idx;


		for(int i = 1; i <= n && posible; i++) {
			idx = pos[i];
			if (per[idx] != 0) {
				if (per[idx] != i) {
					posible = false;
				}
			} else {
				while (idx  < n && per[idx] == 0) {
					if (a[idx] != i) posible = false;
					per[idx] = i;
					i++;
					idx++;
				} i--;
			}
		}
		cout << (posible?"Yes":"No") << "\n";


	}


}


