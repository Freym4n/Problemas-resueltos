/*
 * Main.cpp
 *
 *  Created on: 16/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
long long m[26][26];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	vector<long long> cont(26);
	memset(m,0,sizeof(m));
	int l;
	int n = s.size();
	long long ans = -1;
	for(int i = 0; i < n; i++) {
		l = s[i] - 'a';
		for(int j = 0; j < 26;j++) {
			m[j][l] += cont[j];
			ans = max (ans, m[j][l]);
		}
		cont[l] ++;
		ans = max (cont[l],ans);
	}

	cout << ans << "\n";
	return 0;
}


