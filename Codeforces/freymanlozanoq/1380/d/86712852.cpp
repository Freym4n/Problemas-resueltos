#include <bits/stdc++.h>

using namespace std;

long long const inf = 1e18;

void solve()  {
    int n,m;
    cin >> n >> m;
    long long x,k,y;
    cin >>  x >> k >> y;
    long long a[n+2];
    a[0] = 0;
    a[n+1] = 0;
    long b[n];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    //check if b is subarray of a
    int j = 0;
    vector<int> segment;
    segment.push_back(0);
    for(int i = 1; i <= n; i++) {
        if (a[i] == b[j])  {
            j++;
            segment.push_back(i);
        }
    }
    segment.push_back(n+1);
    if (j < m)  {
        cout << "-1\n";
        return;
    }
    //check if we need to make changes
    int len = segment.size();
    if (len - 2 == n) {
        cout << "0\n";
        return;
    }
    long long ans = 0;

    for(int i = 0; i < len - 1; i++) {
        int l = segment[i];
        int r = segment[i+1];
        long long len_segment = r - l  - 1;
        if (r - l <= 1) continue;
        long long option1 = inf;
        long long option2 = inf;
        long long maximo = -1;
        for(int j = l + 1; j < r; j++) {
            maximo = max(maximo,a[j]);
        }
        if (len_segment < k && maximo > a[l] && maximo > a[r]) {
            cout << "-1\n";
            return;
        }
        //try with berseker as far as we can
        if (maximo < a[l] || maximo  < a[r]) {
            option1 = (len_segment)*y;
        } else {
            option1 = x + (len_segment-k)*y;
        }
        long long remainder = len_segment%k;
        if (len_segment >= k) {
            option2 = remainder*y + ((len_segment- remainder)/k)*x;
        }
        long long option_choosed  = min(option1,option2);
        if (option_choosed == inf) {
            cout << "-1\n";
            return;
        }
        ans += option_choosed;
    }


    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*int t;
    cin >> t;
    while(t--) {
        solve();
    }*/

    solve();
}
