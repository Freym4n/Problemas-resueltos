#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n; long long k;
    cin >> n >> k;
    long long a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k >= (long long) n) {
        cout << n << "\n";
        return;
    }
    queue<long long> q;
    for(long long d: a ) q.push(d);
    int cont = 0;
    int player = q.front(); q.pop();
    while(cont < k) {
        int player2 = q.front();q.pop();
        if (player2 < player) {
            cont++;
            q.push(player2);
        } else {
            cont = 1;
            q.push(player);
            player = player2;
        }
    }
    cout << player << " \n";



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //cin >> t; while(t--) solve();
    solve();

}
