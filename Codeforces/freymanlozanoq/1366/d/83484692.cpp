
#include <bits/stdc++.h>

using namespace std;

int const MAX = 500000;
int const MAX_A = 1e7 + 1;
int ans[MAX][2];
int least_div[MAX_A];

void sieve() {
    for(int i =0 ; i < MAX_A; i++) least_div[i] = 1;
    for(int i = 2; i*i < MAX_A;i++) {
        if (least_div[i] == 1) {
            for(int j = i*i; j < MAX_A; j+= i) {
                if (least_div[j] == 1) least_div[j] = i;
            }
        }
    }
}

void test(int idx, int x) {
    if (least_div[x] == 1)
        return;
    int ld = least_div[x];
    int d1 = 1;
    int d2 = x;
    while(d2 % ld == 0) {
        d1 *= ld;
        d2 /= ld;
    }
    if (d1 != 1 && d2 != 1 && d1 != d2) {
        ans[idx][0] = d1;
        ans[idx][1] = d2;
    }

}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    memset(ans, -1 , sizeof(ans));
    for(int i = 0; i<  n; i++){
        cin >> a[i];
        test(i,a[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i][0];
        if (i < n - 1) cout << " ";
    } cout << "\n";
    for(int i = 0; i < n; i++) {
        cout << ans[i][1];
        if (i < n - 1) cout << " ";
    } cout << "\n";



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    solve();

}
