#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvll;

int k;
long long n;
long long const mod =  1000000009;

void multiply(vvll &m, vvll &init , bool b) {
    vvll t = m;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            m[i][j] = 0;
            for(int l = 0; l < k; l++) {
                m[i][j] = (m[i][j] + (t[i][l]*(b?init[l][j]:t[l][j]))%mod)%mod;
            }
        }
    }
}

void matrix_exp (vvll &m, vvll &init, ll n) {
    if (n <= 1) return;
    matrix_exp(m,init, n/2);
    multiply(m,init,false);
    if ((n&1)) multiply(m,init,true);
}

void solve() {
    vvll init (k, vector<long long> (k));
        for(int i = 0; i < k; i++)
            for(int j = 0; j < k; j++)
                if (j == k - 1 || i == j + 1) init[i][j] = 1;
                else init[i][j] = 0;
    vvll m = init;
    matrix_exp(m,init,n);
    cout << m[k-1][k-1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    while(k || n) {
        solve();
        cin >> k >> n;
    }
}






