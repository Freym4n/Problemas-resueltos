#include <bits/stdc++.h>

using namespace std;

int const inf = 2000000;
int n;
int search(vector < pair<int,int> > &jars, int x) {
    int l = 0, r = n - 1, mid;
    int best_option = inf;
    while(l <= r) {
        mid =  l +(r - l)/2;
        if (jars[mid].first <= x) {
            if (jars[mid].first == x)
                best_option = jars[mid].second;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return best_option;
}



void solve() {
    cin >> n;
    vector<pair <int,int>> left (n);
    vector<pair <int,int>> right (n);
    int cont_blue = 0;
    int cont_red = 0;
    int x;
    vector<int> in (n*2);
    for(int i = 0; i < 2*n; i++) {
        cin >> in[i];
        if (in[i] == 2) cont_blue ++;
        else cont_red ++;
    }
    int tb = cont_blue,tr = cont_red;
    for(int i = n; i < n*2; i++) {
        if (in[i] == 2) tb--;
        else tr--;
        right[i - n] = {tb,tr};
    }
    tb = 0; tr = 0;
    for(int i = n-1; i >= 0;i --) {
        if (in[i] == 2) tb++;
        else tr++;
        int dif = tb - tr;
        left[i] = {dif,i};
    }
    sort(left.begin(), left.end());
    int init = search(left,cont_blue - cont_red);
    int ans = inf;
    if (init != inf) {
        ans = n - init;
    }
    if (cont_blue == cont_red) {
        ans = 0;
    }
    for(int i = 0; i < n; i++) {
        int delta = right[i].first - right[i].second;
        if (delta == 0) {
            ans = min (ans, i+1);
        }
        else  {
            int idx = search(left,delta);
            if (idx == inf) continue;
            ans = min(ans, i + 1 + (n - idx));

        }
    }
    cout << ans << "\n";
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
