/*
 * Main.cpp
 *
 *  Created on: 24/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int const inf = 1000000001;
int const MAX = 2001;
int dx[MAX][10];
int dp[MAX][MAX];
string digits[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int N,K;


int change(string a, string b) {
	int cont = 0;
	for(int i = 0; i < 7; i++) {
		if (a[i] == b[i]) continue;
		if (a[i] == '0') cont++;
		else return inf;
	}
	return cont;
}

void solve_dx(int idx, string s) {
	for(int i = 0; i < 10; i++) {
		dx[idx][i] = change(s,digits[i]);
	}
}

void solve() {
	for(int k = 0; k <= K; k++) {
		int x = -inf;
		for(int d = 0; d < 10; d++) {
			if (dx[0][d] != k) continue;
			x = d;
		}
		dp[0][k] = x;
	}
	for(int n = 1;n < N; n++) {
		for(int k = 0; k <= K; k++) {
			int x = -inf;
			for(int d = 0; d < 10; d++) {
				if (dx[n][d] > k) continue;
				int dif = k - dx[n][d];
				if (dp[n-1][dif] == -inf) continue;
				x = d;
			}
			dp[n][k] = x;
		}
	}
	if (dp[N-1][K] == -inf) {
		cout << "-1\n";
		return;
	}
	int k = K;
	int n = N-1;
	int num;
	vector<int> result;
	while(n >= 0) {
		num = dp[n][k];
		result.push_back(num);
		k -= dx[n][num];
		n--;
	}
	for(int i = 0; i < N; i++) {
		cout << result[i] << "";
	} cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	string s;
	for(int i = 0; i < N; i++) {
		cin >> s;
		solve_dx(N-i-1,s);
	} solve();


}


