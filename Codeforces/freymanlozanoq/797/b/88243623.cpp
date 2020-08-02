#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    int a[n];
    vector<int> odd ,even;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]%2 != 0) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }
    int len1 = odd.size();
    int len2 = even.size();
    sort(odd.rbegin(),odd.rend());
    int sum = odd[0];
    for(int i = 2; i < len1; i+= 2) {
        if (odd[i] + odd[i-1] > 0) sum += odd[i] + odd[i-1];
    }
    for(int i = 0; i < len2; i++) {
        if (even[i]>0) sum += even[i];
    }
    cout << sum << "\n";


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    //cin >> t; while(t--) solve();
    solve();

}
