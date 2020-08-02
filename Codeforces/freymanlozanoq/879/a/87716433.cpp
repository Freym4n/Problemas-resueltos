#include <bits/stdc++.h>

using namespace std;

int next (long long t, long long s, long long d) {
    if (t < s) return s;
    long long x  = t - s ;
    long long  div = x / d;
    return (div+1)*d + s;


}

void solve()  {
    int n;
    cin >>n;
    vector<pair<long long,long long>> a (n);
    for(int i = 0; i < n; i++) {
        long long s,d;
        cin >> s >> d;
        a[i] = {s,d};
    }
    long long t = 0;
    for(int i = 0; i < n; i++) {
        t = next(t,a[i].first,a[i].second);
    }
    cout << t<<"\n";


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //scin >> t; while(t--) solve();
    solve();

}
