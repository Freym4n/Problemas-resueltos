#include <bits/stdc++.h>

using namespace std;

long long bin_search(long long x, vector<long long> &v) {
    int low = 0, high = v.size()-1;
    long long best_option = 0;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if (v[mid] >= x) {
            best_option = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return best_option;
}

void solve() {
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    vector<long long> d;
    for(int i = 0; i < n-1; i+=2) {
        d.push_back(a[i+1]-a[i]);
    }
    vector<long long> d1;
    for(int i = 1; i < n-1; i+=2) {
        d1.push_back(a[i]-a[i+1]);
    }
    int len = d.size();
    long long temp = 0;
    long long ans = 0;
    for(int i = 0; i < len; i++) {
        temp = max(temp + d[i], d[i]);
        ans = max(temp,ans);
    }
    int len1 = d1.size();
    long long temp1 = 0;
    long long ans1 = 0;
    for(int i = 0; i < len1; i++) {
        temp1 = max(temp1 + d1[i], d1[i]);
        ans1 = max(temp1,ans1);
    }

    ans = max(ans,ans1);



    for(int i = 0; i <n; i+=2) {
        ans += a[i];
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
