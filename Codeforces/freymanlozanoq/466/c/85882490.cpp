#include <bits/stdc++.h>

using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    long long a[n];
    long long prefix[n];
    long long total  = 0;
    for(int i = 0; i <n; i++) {
        cin >> a[i];
        total += a[i];
        prefix[i] = total;
    }
    long long ans = 0;
    if (total %3 != 0 || n<3) {
        cout << ans << "\n";
        return 0;
    }
    map<long long, int> m;
    total/=3;
    total*=2;
    long long temp = total/2;
    for(int i = 0; i< n-1; i++) {
        if (prefix[i] == total) {
            ans += m[temp];
        }
        m[prefix[i]]++;
    }
    cout << ans << "\n";



}
