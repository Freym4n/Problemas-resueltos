
#include <bits/stdc++.h>

using namespace std;

int const MAX = 8000;
int a[MAX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t,n0,n1,n2;
    cin >> t;
    while(t--) {
        cin >> n0 >> n1 >> n2;
        string ans;
        if (n2 > 0) {
            for(int i = 0; i < n2 + 1; i++) {
                ans.push_back('1');
            }
        }
        int temp = 0;
        if (n1 > 0) {
            if (n2 > 0) {
                ans.push_back('0');
            } else  {
                ans += "10";
            }
            temp ++;
        }
        for(int i = 0; i < n0; i++) {
            ans.push_back('0');
        }
        if (n1 == 0 && n0 > 0) {
            ans.push_back('0');
        }
        int p = 1;
        for(int i = 0; i < n1-temp; i++) {
            if ((p&1)) ans.push_back('1');
            else ans.push_back('0');
            p++;
        }
        cout << ans << "\n";

    }

}
