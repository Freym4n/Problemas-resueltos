/*
 * Main.cpp
 *
 *  Created on: 13/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;

int sudo[9][9];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int last;
	while(t--) {
		string s;
		for(int i =0 ; i < 9; i++) {
			cin >> s;
			for(int j = 0; j < 9; j++) {
				sudo[i][j] = s[j]-'0';
				if (sudo[i][j] == 1) {
					sudo[i][j] = 2;
				}
			}
		}

		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9 ; j++) {
				cout << sudo[i][j];
			} cout << "\n";
		}
	}
	return 0;
}


