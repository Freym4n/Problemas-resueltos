
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> s;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if (s.count(a[i]) > 0) continue;
        if (q.size() >= k) {
                int deleted = q.front();
                q.pop();
                s.erase(deleted);
        }
        s.insert(a[i]);
        q.push(a[i]);
    }
    int len = q.size();
    cout << len << "\n";
    stack<int> st;
    for(int i = 0; i < len; i++) {
        st.push(q.front());
        q.pop();
    }
    for(int i = 0; i < len; i++) {
        cout << st.top();
        if (i < len - 1 ) cout << " ";
        st.pop();
    }
}
