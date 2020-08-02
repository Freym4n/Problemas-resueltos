/*
 * Main.cpp
 *
 *  Created on: 13/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;

int const MAX  = 200001;

int freq[MAX];
int unicos, rep;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		memset(freq,0,sizeof(freq));
		int n;
		cin >> n;
		int a[n];
		unicos =0;
		rep = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if (freq[a[i]] == 0) {
				unicos ++;
			}
			freq[a[i]] ++;
			rep = max(rep,freq[a[i]]);
		}
		int ans = 0;
		if (unicos > rep) {
			ans = min(unicos,rep);
		} else {
			ans = min (unicos, rep-1);
		}
		cout << ans << "\n";
	}

	return 0;
}


