#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    int f[n];
    bool falta[n+1];
    for(int i = 0; i < n + 1; i++) {
        falta[i] = false;
    }
    for(int i = 0; i < n; i++) {
        cin >> f[i];
        falta[f[i]] = true;
    }
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        if (!falta[i]) {
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    queue<int> q;
    for(int i = 0; i < v.size(); i++) {
        q.push(v[i]);
    }

    for(int i = 0; i < v.size() ; i++) {
        if (f[v[i]-1] == 0) {
            while(q.front() == v[i]) {
                q.push(q.front());
                q.pop();
            }
            f[v[i]-1] = q.front();
            q.pop();
        }
    }

    for(int i = 0; i < n && !q.empty(); i++) {
        if (f[i] == 0) {
            while(q.front() == i+1) {
                q.push(q.front());
                q.pop();
            }
            f[i] = q.front();
            q.pop();
        }
    }
    for(int i = 0; i < n; i++) {
        cout << f[i];
        if (i < n - 1) cout << " ";
    } cout << "\n";


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
