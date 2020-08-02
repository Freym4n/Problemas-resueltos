/*
 * Main.cpp
 *
 *  Created on: 1/05/2020
 *      Author: Freyman
 */

#include <bits/stdc++.h>

using namespace std;

int freq[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
       int n,k;
       cin >> n >> k;
       string s;
       cin >> s;
       sort(s.begin(),s.end());
       string s1;
       vector< string > v(k);
       for(int i = 0; i < n; i ++) {
            v[i%k].push_back(s[i]);
            if (v[i%k].compare(s1) > 0) {
                s1 = v[i%k];
            }
       }
       string s2;
       for(int i = k-1; i < n; i++) {
            s2.push_back(s[i]);
       }
       string result;
       if (s1.compare(s2) > 0) {
            result = s2;
       } else {
           result = s1;
       }
       int cont = 1;
       while (cont < n) {
            if (s[cont] == s[cont-1]) {
                cont ++;
            } else {
                break;
            }
       }
       if (cont  < k ) {
            result = s[k-1];
       }

      //cout << s1 << " " << s2 << "\n";
       cout << result << "\n";

    }
	return 0;

}
