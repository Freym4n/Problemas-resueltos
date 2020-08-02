
#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cont =0 ;
    for(int i = 0; i <n; i++) {
        if (s[i] =='W') cont++;
    }
    if (cont%2  == 1 && (n-cont)%2 == 1) {
        cout << "-1\n";
        return;
    }
    vector<int> op;
    int contw = cont;
    int contb = n - cont;
    int comp;
    if (contw%2 == 0) comp = 'W';
    else comp = 'B';
    bool flag = 0;
    int dist = 0;
    for(int i = 0; i <n; i++) {
        dist ++;
        if (s[i] == comp) {
            if (flag) {
                for(int j = i-1; j >= i - dist; j--) {
                    op.push_back(j);
                }
                op.push_back(i - dist - 1);
                dist = -1;
            } else {
                dist = -1;
            }
            flag^=1;
        }
    }
    cout << op.size() << "\n";
    for(int i: op) cout << (i+1) << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();

}

