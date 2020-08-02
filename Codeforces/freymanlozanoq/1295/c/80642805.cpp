#include <bits/stdc++.h>

using namespace std;


int search( vector<int> &arr, int x) {
    int n = arr.size();
    int l = 0, r = n -1 , mid ;
    int best_option = -1;
    while(l <= r) {
        mid = (l + r)/2;
        if (arr[mid] >  x) {
            best_option = arr[mid];
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return best_option;
}


void solve() {
    string s,t;
    cin >> s >> t;
    int len = s.size();
    int n = t.size();
    vector< vector<int> > lst (26);
    bool v[26];
    memset(v,false,sizeof(v));
    for(int i = 0; i < len; i++) {
        int idx = s[i] - 'a';
        lst[idx].push_back(i);
        v[idx] = true;
    }
    int ans = 0;
    int i =0;
    while(i < n) {
        ans++;
        int last = -1;
        while (i < n) {
            int curr = t[i] - 'a';
            if (!v[curr]) {
                cout << "-1\n";
                return;
            }
            int idx = search(lst[curr],last);
            if (idx == -1) break;
            i++;
            last = idx;
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
