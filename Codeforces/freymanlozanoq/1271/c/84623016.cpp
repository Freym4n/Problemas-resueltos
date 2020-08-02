
#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n, x1,y1;
    cin >> n >> x1 >> y1;
    vector<int> ans (4,0);
    // u r d l
    while(n--) {
        int x,y;
        cin >> x >> y;
        if (x != x1) {
            if (x - x1 > 0 ) ans[1] ++;
            else ans[3]++;
        }
        if (y != y1) {
            if (y - y1 > 0) ans[0] ++;
            else ans[2]++;
        }
    }
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int maximo = 0;
    int value = 0;
    for(int i = 0; i<  4; i++) {
        if (ans[i] > value) {
                maximo = i;
                value = ans[i];
        }
    }
    int ansx = x1 + dx[maximo];
    int ansy = y1 + dy[maximo];
    cout << ans[maximo] << "\n";
    cout << ansx << " " << ansy << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();

}

