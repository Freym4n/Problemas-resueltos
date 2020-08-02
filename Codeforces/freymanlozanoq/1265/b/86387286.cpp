#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n;
    cin >> n;
    int a[n];
    int pos[n+1];
    for(int i = 0; i< n; i++) {
        cin >> a[i];
    }
    vector<int> li (n,0);
    vector<int> ls (n,0);
    vector<pair<int,int>> s;
    s.push_back({n+1,-1});
    for(int i = 0; i <n; i++) {
        while(a[i] > s.back().first) s.pop_back();
        li[i] = s.back().second;
        s.push_back({a[i],i});
    }
    s.clear();
    s.push_back({n+1,n});
    for(int i = n-1; i >= 0; i--) {
        while(a[i] > s.back().first) s.pop_back();
        ls[i] = s.back().second;
        s.push_back({a[i],i});
    }
    string ans (n,'1');
    for(int i = 0; i < n; i++) {
        int l = li[i] + 1;
        int r  = ls[i] - 1;
        if (r - l  + 1 < a[i]) ans[a[i]-1] = '0';
    }
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
