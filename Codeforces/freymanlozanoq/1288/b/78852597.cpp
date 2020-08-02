
#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    double a,x,b;
    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        x = floor(log10(b)) + 1;
        if (floor(log10(b+1)) + 1 == x) {
            x--;
        }
        x*=a;
        long long ans = (long long) x;
        cout << ans << "\n";
     }

	return 0;

}
