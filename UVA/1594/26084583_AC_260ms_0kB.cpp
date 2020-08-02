
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a (n);
        vector<int> ducci(n,0);
        for(int i = 0; i <n; i++)
            cin >> a[i];
        int sum = 0;
        bool zero = false;
        for(int rep = 0; rep <= 1000 && !zero; rep++) {
            sum = 0;
            for(int i = 0; i < n; i++) {
                ducci[i] = abs(a[i] - a[(i+1)%n]);
                sum += ducci[i];
            }
            if (sum == 0) zero = true;
            swap(ducci,a);
        }
        cout << (zero?"ZERO":"LOOP") << "\n";
    }
}

