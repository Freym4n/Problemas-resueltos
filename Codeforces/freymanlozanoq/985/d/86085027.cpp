#include <bits/stdc++.h>

using namespace std;

long long n,h;

long long f(long long x) {
    if (x%2 == 0) {
        return (x/2)*(x+1);
    }
    return x*((x+1)/2);
}

long long const inf = 2e9;

long long bin_search() {
    // maximo x tal que x*(x+1)/2 <= n && x <= k
    long long low = 1,high = min(inf,h);
    long long ans = 0;
    while(low <= high) {
        long mid = low + (high - low)/2;
        if (f(mid) <= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;

}

long long t(long long x) {
    return f(h) + h*(x-h);
}
long long g(long long x) {
    long long temp = (x-h-1)/2;
    temp = temp*(temp+1);
    if (((x-h+1)&1)) temp += (x-h+1)/2;
    return temp;
}

void solve() {
    cin >> n >> h;
    long long n1 = bin_search();
    long long r = n - f(n1);
    long long ans = n1 + ((r + n1 - 1)/n1);
    if (n1 < h) {
        cout << ans << "\n";
        return;
    }
    //find min x such that g(x,h) >= t(x)
    //t = n - h*(h+1)/2 - h*(x-h)
    //g = ((x-h)/2)*((x-h)/2 + 1)
    long long low = 0, high = inf;
    while(low <= high) {
        long long mid = low + (high - low)/2;
        if (g(mid) + t(mid) >= n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin >> t;
    //while(t--) {
        solve();
    //}
}
