/*
 * Main.cpp
 *
 *  Created on: 17/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int const inf = 1000000001;

int idx[31];
int cont[31];
int k,n;
int const MAX = 400001;
int bit[MAX];

int get_max(int a, int b) {
	int temp = min(a,b);
	temp = k - temp;
	return a + b + temp;
}

int get_min(int a, int b) {
	int temp = max(a,b);
	return a+b -(temp-1);
}

void add(int value, int idx) {
	for(int i = idx; i <= k+ k ; i = (i|(i+1))) {
		bit[i] += value;
	}

}

void range_add(int l, int r, int value) {
	if (l > r) return;
	add(value,l);
	add(-value,r+1);
}

int query(int idx) {
	int result = 0;
	for(int i  = idx; i >= 0; i = (i&(i+1))-1) {
		result += bit[i];
	}
	return result;
}

void sum(int a, int b) {
	int mini = get_min(a,b);
	int maxi = get_max(a,b);

	range_add(2,mini-1,2);
	range_add(mini,a+b-1,1);
	range_add(a+b+1, maxi,1);
	range_add(maxi+1,k+k,2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int a[n];
		for(int i = 0; i <= k+k; i++) {
			bit[i] = 0;
		}
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < n/2; i++) {
			sum(a[i],a[n-i-1]);
		}
		int ans = inf;
		for(int i = 2; i <= k+k ; i++) {
			ans = min(ans,query(i));
		}
		cout << ans << "\n";
	}


}


