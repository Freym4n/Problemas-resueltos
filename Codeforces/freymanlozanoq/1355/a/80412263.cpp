#include <bits/stdc++.h>

using namespace std;

pair<long long,long long> maxmin(long long val) {
    long long maxi = 0;
    long long mini = 9;
    while(val) {
        mini= min(mini,val%10);
        maxi= max(maxi,val%10);
        val/=10;
    }
    return {mini,maxi};
}

void solve() {
    long long k,a;
    cin >> a >> k;
    for(int i = 1; i < k; i++) {
        pair<long long,long long> temp = maxmin(a);
        a += temp.first*temp.second;
        if (temp.first*temp.second == 0) break;
    }
    cout << a << "\n";

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
