/*
 * Main.cpp
 *
 *  Created on: 26/04/2020
 *      Author: Freyman
 */

#include <bits/stdc++.h>
# define M_PI 3.14159265358979323846


using namespace std;
int const inf = 1000000001;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	long long a,b,x,y,ans;
	while(t--) {
		cin >> x >> y;
		cin >> a >> b;
		long long ma = max(abs(x),abs(y));
		long long mi = min(abs(x),abs(y));
		if (b <= a*2) {
			ans = mi*b + (ma-mi)*a;
		} else {
			ans = (x+y)*a;
		}
		cout << ans << "\n";
	}
	return 0;

}


