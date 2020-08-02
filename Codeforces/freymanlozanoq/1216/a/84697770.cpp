
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int cont =0 ;
    for(int i = 1; i < n; i+=2) {
        if (s[i] != s[i-1]) continue;
        if (s[i] == 'a') s[i] = 'b';
        else  s[i] = 'a';
        cont++;
    }
    cout << cont << "\n";
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();



}

