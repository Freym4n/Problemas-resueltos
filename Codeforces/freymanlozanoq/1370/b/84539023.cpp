
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n*2];
    int contp = 0, conti =0 ;
    for(int i = 0; i < 2*n; i++) {
        cin >> a[i];
        if (a[i]%2 == 0) contp ++;
        else conti++;
    }
    int cont_deleted = 0;
    if (conti % 2 == 1) {
        for(int i = 0; i < 2*n; i++) {
            if (a[i]%2 == 1) {
             a[i] = -1;
             cont_deleted++;
             break;
            }
        }
    }
    int idx = 0;
    while (cont_deleted < 2 && idx < 2*n) {
        if (a[idx]%2 != 0) { idx++; continue;}
        a[idx] = -1;
        cont_deleted++;
        idx++;
    }
    vector<pair<int,int>> b;
    for(int i = 0; i < 2*n; i++) {
        if (a[i] == -1 ) continue;
        for(int j = 0; j < 2*n; j++) {
            if (i == j) continue;
            if (a[j] == -1) continue;
            if (a[i]%2 != a[j]%2) continue;
            b.push_back({i+1,j+1});
            a[i] = -1;
            a[j] = -1;
        }
    }
    for(int i = 0; i < n - 1; i++) {
        cout << b[i].first << " " << b[i].second << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

}

