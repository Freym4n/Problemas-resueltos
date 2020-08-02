
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i <n; i++) cin >> a[i];
    pair<int,int> queries[n+1];
    int i = 0;
    for(; i <n -1 ; i++) {
        int f = a[i];
        int s = a[i+1];
        queries[i+1] = {f,s};
        a[i+1] = max(f, s);
        a.push_back(min(f, s));
    }
    while(q--) {
        long long m;
        pair<int,int> ans;
        cin >> m;
        if (m < n) ans = queries[m];
        else {
            m -= n;
            int f = a[i];
            int s = a[(i+1) + m%(n-1)];
            ans = {f,s};
        }
        cout << ans.first << " " << ans.second << "\n";
    }
}

