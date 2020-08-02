
#include <bits/stdc++.h>

using namespace std;
int const MAX = 400001;
int n;
bool v[MAX];
int a[MAX];


int mod(int x) {
    if (x >= 0) return x%n;
    x = abs(x)%n;
    return  (n-x)%n;
}

int f(int i) {
    return (i) + mod(a[i]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n*2; i++) {
            v[i] = false;
        }
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            v[f(i)%n] = true;
        }
        int cont = 0;
        bool posible = true;
        for(int i = 0; i < n; i++) {
           if (!v[i]) posible = false;
        }
        cout << (posible?"YES":"NO")  << "\n";
    }

	return 0;

}
