#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int f[3][3];
    memset(f,0,sizeof f);
    for(int i = 0; i < k; i++) {
        if (s[i] == 'R') {
            f[i%3][0] ++;
        } else if (s[i] == 'G') {
            f[i%3][1] ++;
        } else {
            f[i%3][2] ++;
        }
    }
    /*for(int i = 0; i < 3;i++) {
        for(int j = 0; j < 3; j++) {
            cout << f[i][j] << " ";
        } cout << "\n";
    }*/
    int op1 = k - f[0][0] - f[1][1] - f[2][2];
    int op2 = k - f[1][0] - f[2][1] - f[0][2];
    int op3 = k - f[2][0] - f[0][1] - f[1][2];
    int ans = min(op1,min(op2,op3));
    for(int i = 0; i < n - k; i++) {
        if (s[i] == 'R') {
            f[i%3][0] --;
        } else if (s[i] == 'G') {
            f[i%3][1] --;
        } else {
            f[i%3][2] --;
        }
        if (s[i+k] == 'R') {
            f[(i+k)%3][0] ++;
        } else if (s[i+k] == 'G') {
            f[(i+k)%3][1] ++;
        } else {
            f[(i+k)%3][2] ++;
        }
        op1 = k - f[0][0] - f[1][1] - f[2][2];
        op2 = k - f[1][0] - f[2][1] - f[0][2];
        op3 = k - f[2][0] - f[0][1] - f[1][2];
        ans = min(min(ans,op1),min(op2,op3));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    //solve();

}
