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
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i <  n; i++) {
		cin >> a[i];
	}
	for(int i = 30; i >= 0; i--) {
		for(int j = 0; j <n ; j++) {
			if (a[j]&(1<<i)) {
				cont[i]++;
				idx[i] = j;
			}
		}
	}
	int first = 0;
	for(int i = 0; i < 31; i++) {
		if (cont[i] != 1) continue;
		first = idx[i];
	}
	cout << a[first];
	for(int i = 0; i < n; i++) {
		if (i == first) continue;
		cout << " "<<a[i];
	} cout << "\n";

}


