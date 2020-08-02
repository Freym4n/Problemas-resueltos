
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    vector<int> contp(n+1,0);
    set<int> p;
    priority_queue<int> used;
    priority_queue<int> unused;
    int maximo = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        maximo = max(maximo, a[i]);
        contp[a[i]]++;
    }
    for(int i = 0; i <= maximo - 1; i++) {
        if (contp[i] > 0) continue;
        unused.push(-i);
    }
    used.push(-(n+1));
    int ans[n];
    bool possible = true;
    for(int i = 0; i < n; i++) {
        if (unused.empty()) {
            ans[i] = abs(used.top());
        } else {
            int temp = abs(unused.top());
            unused.pop();
            ans[i] = temp;
            used.push(-temp);
        }
        contp[a[i]] --;
        if (contp[a[i]]== 0) {
            unused.push(-a[i]);
        }
    }
    for(int i = 0; i <  n; i++){
        cout << ans[i] << " ";
    } cout << "\n";




}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();

}
