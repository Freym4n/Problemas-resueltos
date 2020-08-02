#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k;
        long long min_div = n;
        for(int i =2 ; i <  n; i++) {
                if (n%i==0) {
                        min_div = i;
                        break;
                }
        }
        n += min_div;
        n += (2*(k-1));
        cout << n << "\n";
    }
}
