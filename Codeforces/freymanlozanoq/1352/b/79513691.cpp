
#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<int> ans;
        if  ((n&1)==0  && n >= k*2) {
            for(int i = 0; i < k-1; i++) {
                ans.push_back(2);
            }
            ans.push_back(n - 2*(k-1));
        } else if ((n&1) && (k&1) && k <= n) {
            for(int i = 0; i < k - 1 ; i++) {
                ans.push_back(1);
            }
            ans.push_back(n - (k - 1));
        } else if ((n&1)==0 && (k&1)==0 && k <= n) {
            for(int i = 0; i < k - 1; i++) {
                ans.push_back(1);
            } ans.push_back(n - (k - 1));
        } else {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i< k ; i++) {
            cout << ans[i];
            if ( i < k -1 ) cout << " ";
        } cout << "\n";
    }

}
