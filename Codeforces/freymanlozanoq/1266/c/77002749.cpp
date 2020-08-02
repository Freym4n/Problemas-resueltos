/*
 * Main.cpp
 *
 *  Created on: 16/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int r,  c;
	cin >> r >> c;
	if (r == 1 && c == 1) {
		cout << "0\n";
		return 0;
	}
	int a[max(r,c)][min(c,r)];
	int l = min(r,c);
	for(int i = 0; i < l; i++) {
		a[0][i] = i*2 + 2;
	}
	for(int i = 1; i < l; i++) {
		a[i][0] = i*2 + 1;
	}
	int cont = 2 * min(r,c) + 1;
	for(int i = l; i < max(r,c); i++) {
		a[i][0] = cont;
		cont++;
	}

	for(int i = 1; i < max(r,c); i++) {
		for(int j = 1; j < min(r,c); j++) {
			a[i][j] = a[0][j] * a[i][0];
		}
	}
	if (r > c)
		for(int i = 0; i < r;i++) {
			for(int j = 0; j < c; j++) {
				cout << a[i][j];
				if (j < c - 1) cout << " ";
			}
			cout << "\n";
		}
	else
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++ ){
				cout << a[j][i];
				if (j < c - 1) cout << " ";
			}
			cout << "\n";
		}
	return 0;
}


