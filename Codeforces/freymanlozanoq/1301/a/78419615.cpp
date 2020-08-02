/*
 * Main.cpp
 *
 *  Created on: 26/04/2020
 *      Author: Freyman
 */

#include <bits/stdc++.h>

using namespace std;




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	string a,b,c;
	while(t--) {
        cin >> a >> b >> c;
        bool posible = true;
        int n = a.size();
        for(int i = 0; i <  n; i++) {
           if (!(c[i] == b[i]  || c[i] == a[i] || (a[i] == b[i] && a[i] == c[i]))) posible = false;
        }
        cout << (posible?"YES":"NO") << "\n";
	}
	return 0;

}
