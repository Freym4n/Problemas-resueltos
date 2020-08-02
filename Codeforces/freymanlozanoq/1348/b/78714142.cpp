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
        memset(freq,0,sizeof(freq));
        int n,k;
        cin >> n >> k;
        int a[n];
        bool posible = true;
        int cont_unique = 0;
        priority_queue<int> q;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if (freq[a[i]] == 0) {
                    cont_unique++;
                    q.push(a[i]);
                    freq[a[i]] ++;
            }
        }
        if (cont_unique > k) {
            cout << "-1\n";
            continue;
        }
        queue<int> q2;
        while(!q.empty()) {
            q2.push(q.top());
            q.pop();
        }
        for(int i = cont_unique ; i < k; i++) {
            q2.push(q2.back());
        }
        cout << (n*n) << "\n";
        for(int i = 0; i < (n*n); i++) {
            cout << q2.front();
            q2.push(q2.front());
            q2.pop();
            if (i < (n*n)-1) cout << " ";
        } cout << "\n";

    }
	return 0;

}
