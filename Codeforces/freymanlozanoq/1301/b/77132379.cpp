/*
 * Main.cpp
 *
 *  Created on: 16/04/2020
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
	int minimo,maximo;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		minimo = inf;
		maximo = -1;
		for(int i = 0; i < n; i++) {
			if (a[i] == -1) continue;
			if ((i == 0 && a[i+1] == -1) ||( i == n-1 && a[i-1] == -1)){
				maximo = max(maximo,a[i]);
				minimo= min(minimo,a[i]);
			} else if (a[i-1] == -1 || a[i+1] == -1) {
				maximo = max(maximo,a[i]);
				minimo = min(minimo,a[i]);
			}
		}
		int k = minimo + (maximo - minimo)/2;
		for(int i = 0; i < n; i++) {
			if(a[i] == -1 ) a[i] = k;
		}
		int ans = 0;
		for(int i = 1; i < n; i++) {
			ans = max(ans, abs(a[i]-a[i-1]));
		} cout << ans << " " << k << "\n";
	}
}


