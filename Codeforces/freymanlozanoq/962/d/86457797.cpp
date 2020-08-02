#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n;
    cin >> n;
    long long a[n];
    priority_queue<long long> q;
    map<long long, priority_queue<int>> m;
    for(int i = 0; i <n; i++) {
        cin >> a[i];
        m[a[i]].push(-i);
        if (m[a[i]].size()%2 == 0) {
            q.push(-a[i]);
        }
    }
    while(!q.empty()) {
        long long x = abs(q.top()); q.pop();
        int removed = abs(m[x].top()); m[x].pop();
        a[removed] = -1;
        int pos = abs(m[x].top()); m[x].pop();
        a[pos] =(long long) x*2;
        m[a[pos]].push(-pos);
        if (m[x*2].size()%2 == 0) {
            q.push(-(x*2));
        }
    }
    int cont = 0;
    for(long long i: a) {
        if (i != -1) cont++;
    }
    cout << cont << "\n";
    for(long long i: a ) if (i != -1) cout << i << " ";
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin >> t;
    //while(t--) {
        solve();
    //}
}
