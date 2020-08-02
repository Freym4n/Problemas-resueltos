#include <bits/stdc++.h>

using namespace std;

int n,m;

bool is_ok(int i, int j) {
    return i  < n && j < m && i >= 0 && j >= 0;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    vector<int> f(n+1);
    for(int i = 0; i <n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    priority_queue<int> q;
    for(int i = 0; i <= n ; i++) {
        if (f[i] == 0) q.push(-i);
    }
    vector<int> ans;
    vector<bool> v (n+1,false);
    for(int rep = 0; rep < 2*n; rep++) {
        int mex  = abs(q.top()); q.pop();
        int idx  = mex==n?mex-1:mex;
        int value = a[idx];
        if (v[idx]) {
            for(int i = 0; i < n; i++) {
                if(a[i] != i) {
                    value = a[i];
                    idx = i;
                    break;
                }
            }
        }
        if (f[value] == 1) {
            q.push(-value);
        }
        ans.push_back(idx);
        f[value]--;
        a[idx] = mex;
        v[idx] = true;
        f[mex]++;
    }
    cout << ans.size() << "\n";
    for(int i: ans) cout << (i+1) << " ";
    cout << "\n";

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
