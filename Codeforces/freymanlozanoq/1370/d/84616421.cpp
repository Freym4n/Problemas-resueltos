
#include <bits/stdc++.h>

using namespace std;


bool build(int n,int l, int x, vector<int> &a) {
    int idx = 0;
    int len = 0;
    while(idx < n) {
        if ((len&1) == 0) {
            idx++;
            len++;
        } else {
            while(idx < n && a[idx] > x)
                idx++;
            if (idx < n) {
                len++;
                idx++;
            }
        }
    }
    if (len >= l) return true;
    idx = 0;
    len = 0;
    while(idx < n) {
        if ((len&1) == 1) {
            idx++;
            len++;
        } else {
            while(idx < n && a[idx] > x)
                idx++;
            if (idx < n) {
                len++;
                idx++;
            }
        }
    }
    if (len >= l) return true;
    else return false;
}

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int r = 0,l = 1;
    for(int i = 0; i <n; i++) {
        cin >> a[i];
        r = max(r,a[i]);
    }
    int ans = 0;
    while(l <= r) {
        int mid = l +(r - l)/2;
        if (build(n,k,mid,a)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

