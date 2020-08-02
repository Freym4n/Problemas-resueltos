#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n,k;
    cin >> n >> k;
    vector<int> ans;
    int a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if (a%2==1) {
            ans.push_back(i+1);
        }
    }
    int len = ans.size();
    if (len < k || (len - k)%2 == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for(int j = 0; j < k-1; j++) {
            cout << ans[j] << " ";
        } cout << n;
        cout << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    //solve();

}
