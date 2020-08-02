/*
 * Main.cpp
 *
 *  Created on: 23/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int const inf = 1000000001;

int n,k;

int sum[200001];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int a[n];
		for(int i = 0; i<  n; i++) {
			cin >> a[i];
			sum[i] = 0;
		}
		for(int i = 1; i < n - 1; i++) {
			sum[i] = sum[i-1];
			if (a[i-1] < a[i] && a[i] > a[i+1]) {
				sum[i] ++;
			}
		}
		sum[n-1] = sum[n-2];
		int ans = 0;
		int idx = 0;
		int value;
		for(int i = 0; i + k - 1 < n; i++) {
			value = sum[i+k-2] - sum[i];
			if (value > ans) {
				ans = value;
				idx = i;
			}
		}
		cout << (ans+1) << " "  << (idx+1) << "\n";

	}


}


