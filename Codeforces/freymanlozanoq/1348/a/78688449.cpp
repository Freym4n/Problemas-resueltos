/*
 * Main.cpp
 *
 *  Created on: 1/05/2020
 *      Author: Freyman
 */

#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a = 0; long long b  = 0;
        for(int i = 1; i <= (n/2)-1; i++) {
            a += (1<<i);
        }
        a += (1<<n);
        for(int i = n/2; i <= n-1; i++) {
            b += (1<<i);
        }
        cout << abs(a-b) << "\n";
    }
	return 0;

}
