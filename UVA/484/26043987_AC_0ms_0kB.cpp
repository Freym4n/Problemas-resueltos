
#include <bits/stdc++.h>

using namespace std;


void solve() {
    map<long long, int> m;
    long long x;
    vector<long long> keys;
    while(cin >> x) {
        if (!m[x]) keys.push_back(x);
        m[x] ++;
    }
    for(int i = 0; i < keys.size();i++) {
        cout << keys[i] << " " << m[keys[i]] << "\n";
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

