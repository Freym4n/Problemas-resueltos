
#include <bits/stdc++.h>

using namespace std;


void solve(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int contl = 0 , contr = 0;
    for(int i =0 ; i <n - 1; i++) {
        if (a[i+1] > a[i]) {
            contr++;
        } else if (a[i+1] < a[i]) {
            contl++;
        }
    }
    cout << "Case " << test << ": " << contr << " " << contl << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    for(int i = 1; i <= c; i++){
        solve(i);
    }
}
