
#include <bits/stdc++.h>

using namespace std;
int const MAX = 25819;
int dp[MAX];
int n;

void prepare() {
    dp[0] = 2;
    for(int i = 1; i < MAX; i++) {
        dp[i] = 2 + dp[i-1] + 3*i;
    }
}

int search(int X) {
    int l = 0,  r = MAX-1,mid;
    int best_option = -1;
    while(l <= r) {
        mid = l + (r-l)/2;
        if (dp[mid] <= X) {
            best_option = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return best_option;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    prepare();
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = 0;
        while (n >= 2) {
            ans ++;
            n -= dp[search(n)];
           // cout << "n " << n << "\n";
        }
        cout << ans << "\n";
    }

	return 0;

}
