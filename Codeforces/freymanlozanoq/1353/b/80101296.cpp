#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,k;
    cin >>n >> k;
    int a[n];
    int b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    vector<int> v;
    for(int i = 0; i < k; i++) {
        v.push_back(a[i]);
        v.push_back(b[n-i-1]);
    }
    sort(v.rbegin(),v.rend());
    for(int i = 0; i < k; i++) {
        a[i] = v[i];
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    cout << sum << "\n";
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
