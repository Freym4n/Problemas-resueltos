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
    string s;
    cin >> s;
    long long ans = 0;
    long long temp = 0;
    long long n = s.size();
    vector<long long > v (n);
    for(int i = 0; i < n; i++) {
        if (s[i] == '+') {
            temp--;
        } else {
            temp++;
        }
        ans = max(ans,temp);
        v[i] = ans;
    }
    long long sum = 0;
    for(int i = 0; i < ans; i++) {
        sum += bin_search(i+1, v) + 1;
        //cout << sum << "\n";
    }
    sum += n;
    cout << sum << "\n";

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
