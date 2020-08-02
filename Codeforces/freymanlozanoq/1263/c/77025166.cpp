/*
 * Main.cpp
 *
 *  Created on: 16/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;

int next(int d,int n) {
	int mod = n%d;
	int div = n/d;
	int result = mod/div + 1;
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int d = 1;
		vector<int> v;
		while (d <= n) {
			v.push_back(n/d);
			d += next(d,n);
		}
		cout << (v.size() + 1) << "\n";
		cout << "0";
		for(int i = v.size() - 1; i >= 0; i--) {
			cout << " "<< v[i];
		} cout << "\n";
	}

	return 0;
}


