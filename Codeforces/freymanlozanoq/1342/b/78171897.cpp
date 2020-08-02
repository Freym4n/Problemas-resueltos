/*
 * Main.cpp
 *
 *  Created on: 26/04/2020
 *      Author: Freyman
 */

#include <bits/stdc++.h>
# define M_PI 3.14159265358979323846


using namespace std;
int const inf = 1000000001;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int contceros = 0, contunos = 0;
		int n = s.length();
		for(int i = 0; i < n; i++) {
			if (s[i] == '0') contceros++;
			else contunos++;
		}
		if (contunos == n || contceros == n) {
			cout << s << "\n";
		} else {
			string p;
			if (s[0] == '0') p = "01";
			else p = "10";
			for(int i = 0; i < n; i++) {
				cout << p;
			} cout << "\n";
		}

	}
	return 0;

}


