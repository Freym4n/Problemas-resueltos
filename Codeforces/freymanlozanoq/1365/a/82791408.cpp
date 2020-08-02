
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

void solve() {
    int n,m;
    cin >> n >> m;
    int a[n][m];
    vector <int> row(n,0);
    vector<int> column(m,0);
    for(int i = 0; i <n; i++) {
        for(int j = 0; j< m ; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }
    int cont = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (row[i] + column[j] == 0) {
                cont++;
                row[i]++;
                column[j]++;
            }
        }
    }
    if (cont%2 == 0) {
        cout << "Vivek\n";
    } else {
        cout << "Ashish\n";
    }
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
