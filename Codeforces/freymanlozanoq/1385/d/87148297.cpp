#include <bits/stdc++.h>

using namespace std;

vector<int> res (200000,0);

int rec (string &s, int idx, int len, int l) {
    if (len == 1) return res[idx];
    int c = l - len;
    int left = 0, right = 0;
    for(int i = idx; i < idx + (1<<(len-1)); i++) {
        if (s[i] - 'a'  != c) left++;
    }
    for(int i = idx + (1<<(len-1)); i < idx + (1<<(len)); i++) {
        if (s[i] - 'a'  != c) right++;
    }
    return min(rec(s, idx + (1<<(len-1)), len-1,l) + left, rec(s,idx, len - 1,l) + right);
}


void solve()  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        if (s[0] == 'a') cout << "0\n";
        else cout << "1\n";
        return;
    }
    int l = log2(n);
    for(int i = 0; i < n-1; i+=2) {
        int op1 = 0;
        if(s[i] - 'a' != l) op1++;
        if (s[i+1] - 'a' != l-1) op1++;
        int op2 = 0;
        if(s[i] - 'a' != l-1) op2++;
        if (s[i+1] - 'a' != l) op2++;
        res[i] = min(op1,op2);
    }
    int ans = rec(s,0,l,l);
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    //solve();

}
