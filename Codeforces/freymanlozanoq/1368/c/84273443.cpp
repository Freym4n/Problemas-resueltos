
#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> ans;
    ans.push_back({0,0});
    ans.push_back({0,1});
    ans.push_back({1,0});
    ans.push_back({1,1});
    pair<int,int> c = {1,1};
    for(int i = 0; i <n; i++) {
        int f = c.first;
        int s = c.second;
        ans.push_back({f+1,s});
        ans.push_back({f,s+1});
        ans.push_back({f+1,s+1});
        c = {f+1,s+1};
    }
    int len = ans.size();
    cout << len << "\n";
    for(int i = 0; i < len; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}

