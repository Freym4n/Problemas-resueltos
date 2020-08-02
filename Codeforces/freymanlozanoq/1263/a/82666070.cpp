
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */





void solve() {
    vector<int> in (3);
    cin >> in[0] >> in[1] >> in[2];
    sort(in.begin(),in.end());
    int dif = min (in[0], in[2] - in[1]);
    int ans = dif;
    in[2] -= dif;
    in[0] -= dif;
    if (in[1] == in[2])
        ans += (in[0] + (in[2] - (in[0]+1)/2));
    else
        ans += in[1];
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
