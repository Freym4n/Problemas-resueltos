/*
 * Main.cpp
 *
 *  Created on: 23/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int const inf = 1000000001;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int n,a,b,c,d;
	while(t--) {
		cin >> n >> a >> b >> c >> d;
		int minimo = a-b;
		int maximo = a+b;
		if (minimo*n > c+d || maximo*n < c-d) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}

}


