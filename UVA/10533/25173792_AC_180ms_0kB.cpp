/*
 * Main.cpp
 *
 *  Created on: 6/04/2020
 *      Author: freim
 */
#include <bits/stdc++.h>

using namespace std;

int const MAX = 1000000;
int sum[MAX];
bool prime[MAX];

bool is_prime_digit(int x) {
	int d = 0;
	while (x) {
		d += x%10;
		x/=10;
	}
	if (!prime[d]) return false;
	return true;
 }

void sieve() {
	memset(prime,true, sizeof(prime));
	prime[1] = false;
	for(int i = 2; (long long) i*i <= MAX; i++) {
		if (prime[i]) {
			for(int j = i*i; j < MAX ; j+=i) {
				prime[j] = false;
			}
		}
	}
}

void solve() {
	for(int i = 2; i < MAX; i++) {
		sum[i] = sum[i-1];
		if (!prime[i]) continue;
		if (is_prime_digit(i)) sum[i]++;
	}
}

int query(int l, int r) {
	return sum[r] - sum[l-1];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,l,r;
	sieve();
	solve();
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&l,&r);
		printf("%d\n",query(l,r));
	}

	return 0;
}


