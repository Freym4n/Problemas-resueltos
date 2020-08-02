
#include <bits/stdc++.h>

using namespace std;


void solve() {
    long long n;
    cin >> n;
    string cf = "codeforces";
    vector<long long> ans (10,1);
    long long sum = 1;
    int idx  = 0;
    while(sum < n) {
        int i = idx%10;
        sum /= ans[i];
        ans[i] ++;
        sum *= ans[i];
        idx++;

    }
    string word;
    for(long long i = 0; i < 10; i++) {
        for(long long j = 0; j < ans[i]; j++) {
            word.push_back(cf[i]);
        }
    }
    cout << word << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

