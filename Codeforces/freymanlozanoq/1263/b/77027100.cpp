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
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v;
		int a;
		map<int,int> m;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			cin >> a;
			m[a] ++;
			v.push_back(a);
		}
		for(int i = 0; i < n; i++) {
			if (m[v[i]] > 1) {
				m[v[i]]--;
				ans++;
				while(m[v[i]] > 0) {
					v[i]++;
					if (v[i]%10 == 0) v[i]-=10;
				}
				m[v[i]]++;
			}
		}
		cout << ans << "\n";
		int len;
		for(int i = 0; i < n; i++) {
			len = max(1,(int)floor(log10(v[i])) + 1);
			for(; len < 4; len++) cout << "0";
			cout << v[i] << "\n";
		}


	}

	return 0;
}


