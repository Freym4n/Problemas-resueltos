/*
 * Main.cpp
 *
 *  Created on: 16/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;

int idx[101];
bool v[101];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		memset(v,false,sizeof(v));
		memset(idx,0,sizeof(idx));
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			idx[a[i]] = i;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = idx[i]; j > 0; j--) {
				if (!v[j]){
					if (a[j] < a[j-1]){
						swap(a[j],a[j-1]);
						v[j] = true;
					}

				}
			}
		}
		for(int i = 0; i < n; i++) {
			cout << a[i];
			if (i < n - 1) cout << " ";
		} cout << "\n";
	}

	return 0;
}


