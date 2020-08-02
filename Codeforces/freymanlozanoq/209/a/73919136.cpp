
#include <bits/stdc++.h>

using namespace std;

long long const m = 1000000007;
int const MAX = 1000001;
long long a[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin >> x;
	if (x == 1) {
		cout << 1 << "\n";
		return 0;
	}
	a[0] = 1;
	a[1] = 2;
	for(int i = 2; i < x; i++) {
		a[i] = (a[i-1] + a[i-2])%m;
	}
	for(int i = 1; i < x; i++) {
		a[i]  = (a[i] + a[i-1])%m;
	}
	cout << a[x-1];
	return 0;
}


