#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n; long long k;
    cin >> n >> k;
    long long a[n];
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    map<long long,int> m;
    long long value = 0, rep= 0;
    for(int i = 0; i <n; i++) {
        a[i] = (k - (a[i]%k))%k;
        if (a[i] == 0) continue;
        m[a[i]]++;
        int temp = m[a[i]];
        if (temp > rep) {
            rep = temp;
            value = a[i];
        } else if (temp == rep){
            if (a[i] > value) {
                value = a[i];
            }
        }
    }
    long long ans = 0;
    if (rep != 0)
        ans = value + (k*(rep-1)) + 1;
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
