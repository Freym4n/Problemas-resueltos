#include <bits/stdc++.h>

using namespace std;



void solve()  {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for(int i = 0; i <n; i++) {
        cin >> a[i];
        sum +=a[i];
    }
    int temp = 0;
    int ans = 0;
    for(int i = 0; i <n; i++){
        temp += a[i];
        if (temp >= (sum+1)/2) {
            ans = i+1;
            break;
        }
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //cin >> t;
    //while(t--) {
        solve();
    //}
}
