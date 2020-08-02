
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<pair<int,int>> v (n);
    for(int i = 0; i <n; i++) {
        cin >> a[i];
        v[i] = {a[i],i};
    }
    sort(v.rbegin(), v.rend());
    long long ans = 0, x = 0;
    for(int i = 0; i < n; i++) {
        ans += v[i].first*x + 1;
        x++;
    }
    cout << ans << "\n";
    for(auto pp: v) {
        cout << (pp.second+1) << " ";
    } cout << "\n";



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();



}

