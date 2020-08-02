
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    vector<int> ans;
    ans.push_back(a[0]);
    for(int i = 1; i < n - 1; i++) {
        if ((a[i] < a[i-1] && a[i] < a[i+1]) || (a[i] > a[i-1] && a[i] > a[i+1])) ans.push_back(a[i]);
    }
    ans.push_back(a[n-1]);
    cout << ans.size() << "\n";
    for(int i = 0; i <  ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << " ";
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
