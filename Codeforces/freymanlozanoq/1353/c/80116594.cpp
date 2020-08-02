#include <bits/stdc++.h>

using namespace std;
int const MAX_SUM = 250001;
long long sum[MAX_SUM];

void prepare() {
    sum[0] = 1;
    for(int i = 1; i < MAX_SUM; i++) {
        sum[i] = 2*(i*2+1) + 2*((i-1)*2 + 1);
    }
}
void solve() {
    long long n;
    cin >> n;
    long long ans = 0;
    for(int i = 0; i*2 + 1 <= n; i++) {
        ans += sum[i]*((long long ) i);
    }
    cout << ans << "\n";
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	prepare();
	while(t--) {
       solve();
	}
}
