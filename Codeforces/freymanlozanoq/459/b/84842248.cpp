
#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i <n; i++) cin >> a[i];
    sort(a, a  + n);
    int max_dif = a[n-1] - a[0];
    if (max_dif == 0) {
        long long ans = n;
        ans *= (ans-1);
        ans /= (long long)2;
        cout << "0 " << ans << "\n";
        return 0;
    }
    int left = 0;
    while(left < n-1 &&  a[left+1] == a[left]) left++;
    int high = n -1;
    while(high > 1 && a[high] == a[high-1]) high--;
    long long ans = (long long) (left+1) * (n-high);
    cout << max_dif << " " << ans << "\n";
}

