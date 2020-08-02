
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a (n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(),a.rend());
    int cont = 0;
    int i =0 ;
    for(; i < n; i++) {
        cont += a[i];
        sum -= a[i];
        if (cont > sum) break;
    }
     cout << (i+1) << "\n";
}

