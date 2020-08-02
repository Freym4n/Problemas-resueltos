
#include <bits/stdc++.h>

using namespace std;

int const  N = 1000001;
long long lcm[N];
long long const m = 100000000;
void prepare_lcm() {
	for(int i = 1; i < N; i++) lcm[i] = i;
	for(int i = 2; i < N; i++)  {
		for(int j = i + i; j < N; j+=i) {
			lcm[j] /= lcm[i];
		}
	}
}

void solve() {
	for(int i = 3; i < N ; i++) {
		lcm[i] *= lcm[i-1];
		while (lcm[i] % 10 == 0) {
			lcm[i] /= 10;
		}
		lcm[i] %= m;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	prepare_lcm();
	solve();
	int x;
	cin >> x;
	while(x) {
		cout << lcm[x]%10 << "\n";
		cin >> x;
	}

	return 0;
}


