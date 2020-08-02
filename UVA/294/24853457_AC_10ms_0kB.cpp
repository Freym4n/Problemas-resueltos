/*
 * divisors.cpp
 *
 *  Created on: 20/03/2020
 *      Author: freyman
 */


#include <bits/stdc++.h>

using namespace std;

int find_divisors(int n ) {
	int num = 1;
	int cont;
	int x = 2;
	while ((long long)x * x <= n) {
		cont = 0;
		while (n % x == 0) {
			cont ++;
			n /= x;
		}
		num *= (cont+1);
		x++;
	}
	if (n > 1) {
		num*= 2;
	}
	return num;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,l,r;
	cin >> t;
	int result = 0;
	int index = 0;
	int temp;
	while(t--) {
		result = 0;
		temp = 0;
		index = 0;
		cin >> l >> r;
		for(int i = l; i <=r ; i++) {
			temp = find_divisors(i);
			if (temp > result) {
				result = temp;
				index = i;
			}
		}
		cout <<"Between "<< l<<" and " << r <<", "<<index<< " has a maximum of "<<result<<" divisors.\n";
	}

	return 0;
}


