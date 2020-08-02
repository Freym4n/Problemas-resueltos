#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,s;
    cin >> n >> s;
    if (n-1 >= s - n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << (s-(n-1));
    for(int i = 0; i < n - 1; i++) {
        cout << " " << 1;
    }
    cout << "\n";
    cout << n << "\n";



}
