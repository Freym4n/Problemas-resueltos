#include <bits/stdc++.h>

using namespace std;

int const inf = 200001;

void solve() {
    long long a,b;
    cin >> a >> b;
    long long dif = abs(a-b);
    long long op = 1;
    bool possible = false;
    if (dif == 0) {
        cout << "0\n";
        return;
    }
    while (!possible) {
        if (op*(op+1)/2 < dif) {
            op++;
        } else if ((op*(op+1)/2)%2 != dif%2) {
            op++;
        } else {
            possible = true;
        }
    }
    cout << op << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }



}
