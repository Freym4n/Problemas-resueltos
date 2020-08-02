/*
 * Main.cpp
 *
 *  Created on: 24/03/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;

int z_function(string s) {
    string rev = string(s.rbegin(), s.rend());
    s += "$";
    s += rev;
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    int res = 0;
    for(int i = n>>1; i < n;i++) {
    	res = max(res,z[i]);
    }
    return  res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,result;
	string s,rev;
	cin >> t;
	while (t--) {
		cin >> s;
		result = z_function(s);
		for(int i = result - 1; i >= 0; i--) {
			cout << s[i];
		}
		cout <<"\n";
	}
	return 0;
}


