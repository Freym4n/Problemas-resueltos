
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "FastestFinger\n";
        return;
    }
    if (n == 2) {
        cout << "Ashishgup\n";
        return;
    }
    if (n % 2 == 1) {
        cout << "Ashishgup\n";
        return;
    }
    if ((n&(n-1)) == 0) {
        cout << "FastestFinger\n";
        return;
    }
    int div = 0;
    int cont_two = 0;
    while(n % 2 == 0)  {
        cont_two++;
        n /=  2;
    }
    for(int p = 3; p*p <= n; p+=2) {
        while (n % p == 0)  {n /= p; div++;}
    }
    if (n > 1) div++;
    if (cont_two == 1) {
        if (div > 1) {
            cout << "Ashishgup\n";
        } else {
            cout << "FastestFinger\n";
        }
    } else {
        cout << "Ashishgup\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

}

