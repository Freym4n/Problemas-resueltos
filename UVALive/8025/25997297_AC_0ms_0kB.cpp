
#include <bits/stdc++.h>

using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c;
    while(cin >> c) {
        vector<pair<int, string>> ans;
        while(c--) {
            string a,b;
            cin >> a >> b;
            int idx = a[0] - '0';
            if (idx <= 9) {
                int num = stoi(a);
                num/= 2;
                ans.push_back({num, b});
            } else {
                int num = stoi(b);
                ans.push_back({num,a});
            }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i].second<< "\n";
        }
    }

}
