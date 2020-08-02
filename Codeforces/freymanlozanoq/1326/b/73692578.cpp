#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for (int i = 0; i < n; i++) cin >> b[i];
	a[0] = b[0];
	int maximun = a[0];
	for(int i = 1; i < n; i++) {
		a[i] = b[i] + maximun;
		if (maximun < a[i]) maximun = a[i];
	}
	cout << a[0];
	for(int i = 1 ; i < n; i++) {
		cout << " "<< a[i];
	} cout << "\n";
}
