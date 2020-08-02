/*
 * Main.cpp
 *
 *  Created on: 6/04/2020
 *      Author: freim
 */
#include <bits/stdc++.h>

using namespace std;

int const MAX = 10001;
int dp[MAX];
int m,n,t;
void solve() {
	int res = 0;
	int dist = 0;
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <=t; i++) {
		if ((i-m) >= 0 && (i-m == 0 || dp[i-m] != 0)) {
			dp[i] = dp[i-m] + 1;
		}
		if ((i-n) >= 0 && (i-n == 0 || dp[i-n] != 0)) {
			dp[i] = max(dp[i],dp[i-n] + 1);
		}
		if (dp[i] != 0) {
			res = dp[i];
			dist = 0;
		} else {
			dist ++;
		}

	}
	printf("%d",res);
	if (dist != 0) printf(" %d\n",dist);
	else printf("\n");
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (scanf("%d %d %d",&m,&n,&t) != EOF) {
		solve();
	}

	return 0;
}


