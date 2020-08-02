
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
        vector<int> ans;
        int cont = 0;
        while(n) {
            if (n % 10 != 0) {
                ans.push_back((n % 10) * pow (10,cont));
            }
            n /= 10;
            cont++;
        }
        int len = ans.size();
        cout << len << "\n";
        for(int i = 0; i < len; i++) {
            cout << ans[i];
            if (i < len - 1) cout << " ";
        }
        cout << "\n";
    }
	return 0;

}
