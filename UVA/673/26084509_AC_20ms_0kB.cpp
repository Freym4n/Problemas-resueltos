
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("output.txt", "w", stdout);
    int t;
    string s;
    getline(cin,s);
    t = stoi(s);
    while(t--) {
        getline(cin, s);
        int n = s.size();
        string ans;
        for(int i = 0; i <n; i++) {
            if (s[i] == '(' || s[i] == '[' || ans.empty()) ans.push_back(s[i]);
            else if ((s[i] == ')' && ans[ans.size()-1] == '(')  || (s[i] == ']' && ans[ans.size()-1] == '[')) {
                ans.pop_back();
            } else {
                ans.push_back(s[i]);
            }
        }
        if (ans.empty()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

