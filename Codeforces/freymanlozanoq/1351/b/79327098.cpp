
#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
        int a,b,c,d;
        cin >> a >> b;
        cin >> c >> d;
        if ((a + c == b && (b == d))  ||  (a  + d == b  && (b == c)) ||  (b + c == a && (a == d)) || (b + d == c && (c == a))) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
	}
	return 0;

}
