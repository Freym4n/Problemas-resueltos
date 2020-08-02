#include <bits/stdc++.h>

using namespace std;



void solve()  {
    long long n;
    cin >> n;
    long long x = 1,y = n-1,t1,t2;
    long long gcd = n-1;
    for(long long i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            t1 = i*((n/i)-1);
            t2 = i;
            long long temp = (t1*t2)/(__gcd(t1,t2));
            if (temp < gcd) {
                x = t1;
                y = t2;
                gcd = temp;
            }
            t1 = (n/i)*(i-1);
            t2 = (n/i);
            temp = (t1*t2)/(__gcd(t1,t2));
            if (temp < gcd) {
                x = t1;
                y = t2;
                gcd = temp;
            }

        }
    }
    cout << x << " " << y << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    //solve();
}
