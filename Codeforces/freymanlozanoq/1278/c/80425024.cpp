#include <bits/stdc++.h>

using namespace std;

int const inf = 200001;

void solve() {
    int n;
    cin >> n;
    vector<int> delta(n*4+1,-1);
    delta[2*n] = n;

    vector<int> in (n*2);
    for(int i = 0; i < n*2; i++) {
        cin >> in[i];
    }
    int dx = 0;
    for(int i = n - 1; i >= 0; i--) {
        if (in[i] == 2) dx++;
        else dx--;
        if (delta[dx+2*n] == -1) delta[dx+2*n] = i;
    }
    dx = 0;
    for(int i = 0; i < n*2; i++) {
        if (in[i] == 2) dx++;
        else dx--;
    }
    int ans = inf;
    int idx = delta[dx + 2*n];
    if (idx != -1 ) ans = n - idx;
    for(int i= n; i < n*2; i++) {
        if (in[i] == 2) {
            dx--;
        } else {
            dx++;
        }
        idx = delta[dx + 2*n];
        if (idx == -1 ) continue;
        ans = min(ans, i+1- idx);
    }
    cout << ans << "\n";
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
