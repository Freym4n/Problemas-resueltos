#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n;
    cin >> n;
    string s; int x;
    vector<int> state (10,0);
    // 0 no changes
    // 1 change
    // 2 off
    // 3 on
    for(int rep  = 0; rep  < n; rep++) {
        cin >> s >> x;
        if (s[0] == '|') {
            for(int i = 0; i < 10; i++) {
                if ((x&(1<<i))) state[i] = 3;
            }
        } else if (s[0] == '&') {
            for(int i = 0; i < 10; i++) {
                if (!(x&(1<<i))) state[i] = 2;
            }
        } else {
            for(int i = 0; i < 10; i++) {
                if ((x&(1<<i))) {
                    if (state[i] == 0) state[i] = 1;
                    else if(state[i] == 1) state[i] = 0;
                    else if (state[i] == 3) state[i] = 2;
                    else state[i] = 3;
                }
            }
        }
    }
    //x1 xor
    //x2 or
    //x3 and
    int x1 = 0,x2 = 0,x3 = 1023;
    cout << "\n";
    for(int i = 0; i < 10; i++) {
        if (!state[i]) continue;
        if (state[i] == 1) x1 = (x1|(1<<i));
        else if (state[i] == 2) x3 = (x3^(1<<i));
        else x2 = (x2|(1<<i));
    }
    cout << "3\n";
    cout << "^ " << x1 << "\n";
    cout << "| " << x2 << "\n";
    cout << "& " << x3 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //cin >> t; while(t--) solve();
    solve();

}
