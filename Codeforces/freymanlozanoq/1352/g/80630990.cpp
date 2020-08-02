#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    if(n < 4 ){
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    int i = n;
    if (i%2 == 0) i--;
    for(; i > 0; i-=2 ) {
        ans.push_back(i);
    }
    ans.push_back(4);
    ans.push_back(2);
    for(i = 6; i <= n; i+=2) {
        ans.push_back(i);
    }
    for(int j = 0; j < n; j++) {
        cout << ans[j];
        if (j < n - 1) cout << " ";
    } cout << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }



}
