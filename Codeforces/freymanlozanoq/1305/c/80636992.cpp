#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i< n; i++) {
        cin >> a[i];
    }
    if (n <= m) {
        vector<int> dif;
        for(int i = 0; i < n -1; i++) {
            for(int j = i + 1; j < n; j++) {
                dif.push_back(abs(a[i] - a[j])%m);
            }
        }
        int ans = 1;
        for(int i= 0; i < dif.size(); i++) {
            ans = (ans * dif[i])%m;
        }
        cout << ans << "\n";
    } else {
        cout << "0\n";
    }


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
