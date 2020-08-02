
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<long long> a (n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> ans (n,0);
    for(int i = 0; i < 30; i++) {
        int cont = 0;
        for(int j = 0 ; j < n; j++) {
            if ((a[j]&(1<<i))) cont++;
        }
        for(int j = 0; j< cont ;j++) {
            ans[j] |= (1<<i);
        }
    }
    long long sum = 0;
    for(int i = 0; i <n; i++) {
        sum += ans[i]*ans[i];
    }
    cout << sum << "\n";


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

