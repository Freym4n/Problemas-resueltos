#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,m;
    cin >>n >> m;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    if (n == 2) {
        cout << m << "\n";
        return;
    }
    cout << 2*m << "\n";
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
