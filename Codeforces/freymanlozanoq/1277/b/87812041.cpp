#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n;
    cin >> n;
    set<int> s;
    priority_queue<int> q;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (!(a[i]&1) && !s.count(a[i])) {
            q.push(a[i]);
            s.insert(a[i]);
        }
    }
    int ans = 0;
    while(!q.empty()) {
        int x = q.top();
        q.pop();
        x>>=1;
        if (!(x&1) && !s.count(x)) q.push(x);
        ans++;
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t; while(t--) solve();
    //solve();

}
