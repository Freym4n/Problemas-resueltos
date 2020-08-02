
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */



void solve() {
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    map<long long, int> last_idx;
    map<long long, int> cont_sum;
    last_idx[0] = -1;
    cont_sum[0] = 1;
    long long sum = 0, last = - 1,cont = 0;
    for(int i = 0; i <n; i++) {
        sum += a[i];
        if (cont_sum[sum]) {
            int l = last_idx[sum];
            if (l >= last) {
                cont += (l - last + 1)*(n - i);
                last = l + 1;
            }
        }
        cont_sum[sum] ++;
        last_idx[sum] = i;
    }
    long long ans = (long long)n*(n+1)/2 - cont;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
