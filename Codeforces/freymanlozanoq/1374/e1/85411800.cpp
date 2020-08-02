#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n,k;
    cin >> n >> k;
    vector<long long> A;
    vector<long long> B;
    vector<long long> BA;
    for(int i = 0; i <n ;i++) {
        long long t,a,b;
        cin >> t >> a >> b;
        if (a+b == 0) continue;
        if (a+b == 2) {
            BA.push_back(t);
        } else if (a==1) {
            A.push_back(t);
        } else {
            B.push_back(t);
        }
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int len_a = A.size();
    int len_b = B.size();
    for(int i = 0; i < min(len_a,len_b); i++) {
        BA.push_back(A[i] + B[i]);
    }
    sort(BA.begin(), BA.end());
    if (BA.size() < k) {
        cout << "-1\n";
        return;
    }
    long long sum = 0;
    for(int i = 0; i < k; i++) {
        sum += BA[i];
    }
    cout << sum << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
