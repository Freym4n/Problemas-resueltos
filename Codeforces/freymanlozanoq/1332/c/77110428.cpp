/*
 * Main.cpp
 *
 *  Created on: 16/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int n,k;
map<int,int> maximos;
map<int, int> elements;
map<int, map <int, int> > mem;

int get_id(int idx) {
	idx%=k;
	idx  = min(idx + 1, k - idx);
	return idx;
}

void add(int idx, int id) {
	elements[id] ++;
	mem[id][idx] ++;
	if (mem[id][idx] > maximos[id]) {
		maximos[id] = mem[id][idx];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >>t;
	while(t--) {
		cin >> n >> k;
		string s;
		cin >> s;
		elements.clear();
		maximos.clear();
		mem.clear();
 		int l;
		for(int i = 0; i < n; i++) {
			l = s[i] - 'a';
			add(l, get_id(i));
		}
		int ans = 0;
		for(int i = 0; i < k/2 + 2; i++) {
			ans += elements[i] - maximos[i];
		}
		cout << ans << "\n";
	}
	return 0;
}


