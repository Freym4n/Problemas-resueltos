
#include <bits/stdc++.h>

using namespace std;

deque<int> q;

void add(int value) {
    while(!q.empty() && q.back() < value) q.pop_back();
    q.push_back(value);
}

void removeq(int value) {
    if (!q.empty() && q.front() ==  value)
        q.pop_front();
}

int get_max() {
    return q.front();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t,c;
    cin >>n >> t >> c;
    vector<int> a(n);
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < c; i++) {
        add(a[i]);
    }
    int ans = 0;
    if (get_max() <= t) ans++;
    for(int i = 1; i < n - c + 1; i++) {
        add(a[i+c-1]);
        removeq(a[i-1]);
        if (get_max() <= t) ans++;
    }
    cout << ans << "\n";
}

