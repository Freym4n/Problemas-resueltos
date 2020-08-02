
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */





void solve() {
    int n;
    cin >> n;
    int p = 2;
    vector <int> div;
    while(p*p <= n) {
        while(n%p == 0) {
            n/=p;
            div.push_back(p);
        }
        p++;
    }
    if (n > 1 )
        div.push_back(n);
    int len = div.size();
    if (len  < 3 ) {
        cout << "NO\n";
        return;
    }
    set<int> ans;
    ans.insert(div[0]);
    int i = 2;
    int t = div[1];
    while (i < len && ans.count(t)) {
        t *= div[i];
        i++;
    }
    ans.insert(t);
    if (i == len ){
        cout << "NO\n";
        return;
    }
    t = div[i];
    i++;
    while(i < len) {
        t*= div[i];
        i++;
    }
    ans.insert(t);
    if (ans.size()  < 3) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i: ans) {
        cout << i << " ";
    } cout << "\n";

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
