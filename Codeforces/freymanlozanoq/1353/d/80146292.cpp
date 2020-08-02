#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    int ans[n + 1];
    priority_queue<pair<int,int>> q;
    q.push({-n,1});
    for(int i = 1; i <=n; i++) {
        pair<int,int> curr = q.top();
        q.pop();
        curr.first = abs(curr.first);
        int l = abs(curr.second);
        int r = l + curr.first - 1;
        int mid = (l + r)/2;
        ans[mid] = i;
        if (r - l + 1 > 1) {
            if(mid - 1 >= 1){
                pair<int,int> left = {(mid-l),-l};
                q.push(left);
            }
            if (r - mid >= 1) {
                pair<int,int> right = {(r-mid),-(mid + 1)};
                q.push(right);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i < n) cout << " ";
    } cout << "\n";
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
