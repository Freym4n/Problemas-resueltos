#include <bits/stdc++.h>

using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        if (a <= b) {
             cout << b << "\n";
        } else {
            if (c <= d) {
               cout << "-1\n";
            } else {
                long long ans = (a-b)/(c-d);
                if((a-b)%(c-d) != 0) {
                    ans++;
                }
                ans*=c;
                ans += b;
                cout << ans << "\n";
            }
        }



    }
}
