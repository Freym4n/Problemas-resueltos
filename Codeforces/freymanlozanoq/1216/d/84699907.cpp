
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    long long a[n];
    long long maximo = 0;
    for(int i =0 ; i <n; i++) {
        cin >> a[i];
        maximo = max(maximo,a[i]);
    }
    for(int i =0 ; i < n; i++) {
        a[i] = maximo - a[i];
    }
    long long gcd = 0, sum = 0;
    for(int i = 0; i <n; i++) {
        if (a[i] != 0) gcd = a[i];
        break;
    }
    for(int i =0 ; i <n; i++) {
        if (a[i] == 0) continue;
        gcd = __gcd(gcd,a[i]);
        sum += a[i];
    }
    long long y = sum/gcd;
    cout << y << " " << gcd << "\n";


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();



}

