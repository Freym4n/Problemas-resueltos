/*
 * Main.cpp
 *
 *  Created on: 16/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int const MAX = 1000001;
int n;
long a[MAX];
int last_visit[MAX];
int last_erase[MAX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int last_check = -1;
	int cont = 0;
	vector<int> result;
	bool posible = true;
	memset(last_visit, -1,sizeof(last_visit));
	memset(last_erase,-1,sizeof(last_erase));
	for(int i = 0; i < n; i++) {
		if (a[i] > 0) {
			if (last_visit[a[i]] > last_check) posible = false;
			last_visit[a[i]] = i;
			cont ++;
		} else {
			if (last_visit[abs(a[i])] <= last_check) posible = false;
			if (last_erase[abs(a[i])] > last_check) posible = false;
			last_erase[abs(a[i])] = i;
			cont--;
		}
		if (cont == 0 && i - last_check != -1) {
			result.push_back(i-last_check);
			last_check = i;
		}
	}
	if (cont != 0) posible = false;
	if (!posible) {
		cout << "-1\n";
		return 0;
	}
	int len = result.size();
	cout << len << "\n";
	for(int i = 0; i < len; i++) {
		cout << result[i];
		if (i < len - 1) cout << " ";
	} cout << "\n";
	return 0;
}


