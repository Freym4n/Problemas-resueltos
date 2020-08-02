#include <bits/stdc++.h>

using namespace std;



void solve() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<long long> ds (b+c+1,0);
    int cont = 0;
    for(int i = 0; i < ds.size(); i++) {
        if ( i <= c) continue;
        if ( i > d+1 && i > 1) ds[i] = ds[d+1] + (d-c+1)*(((long long)i)-d-1);
        else if (i > 0)  {
            ds[i] = ds[i-1] + (i - c);
        }
    }
    long long ans = 0,ly,ry,n,r;
    for(int x = a; x <= b; x++) {
        int high = x + c;
        int low = x + b;
        ans += ds[high]- ds[low-1];
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();


}
