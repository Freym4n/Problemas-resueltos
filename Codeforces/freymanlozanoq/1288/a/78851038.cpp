
#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    double n,d,x1,x2;

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> d;
        double x = sqrt(d) - 1;
        x1 = floor(x);
        x2 = ceil(x);
        if ( (x1 + (d/(x1 + 1))  <= n && x1 >= 0)  || (x2 + (d/(x2 + 1 )) <= n && x2 >= 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
     }

	return 0;

}
