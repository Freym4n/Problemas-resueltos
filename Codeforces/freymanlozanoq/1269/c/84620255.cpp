
#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,k;
    cin >> n >> k;
    int a[n];
    string s;
    cin >> s;
    for(int i = 0; i <n; i++) {
        a[i] = s[i] - '0';
    }
    vector<int> ans;
    vector<int> d (k);
    for(int i = 0; i < k ; i++) {
        d[i] = a[i];
    }
    bool ok = true;
    for(int i = 0; i <n; i++) {
        if(a[i] == d[i%k]) continue;
        if (a[i] < d[i%k]) break;
        ok = false;
    }
    if (!ok) {
        int idx = 0;
        for(int i = 0; i < k; i++) {
            if (d[i] != 9) idx = i;
        }
        d[idx]++;
        for(int i = idx +1 ; i < k; i++ ) {
            d[i]=0;
        }
    }
    for(int i = 0; i < n; i++) {
        ans.push_back(d[i%k]);
    }
    cout << n << "\n";
    for(int i : ans) cout << i;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

