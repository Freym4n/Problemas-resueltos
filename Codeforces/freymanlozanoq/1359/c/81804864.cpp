
#include <bits/stdc++.h>

using namespace std;
double h,c,t;

double f (double x) {
    double ans = (h + (h+c)*x)/(2.0*x+1.0);
    return ans;
}

int search() {
    int l = 0, r = 1000000, mid;
    double ans = abs(h-t);
    int moves = 0;
    while(l <= r) {
        mid = (l + r)/2.0;
        double pro = f(mid);
        if (ans > abs(t-pro) || (ans == abs(t-pro) && moves > mid)) {
            moves = mid;
            ans = abs(t-pro);
        }
        if (t > pro) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }

    }
    int temp = moves - 1;
    double tempf = f(temp);
    if (ans > abs(t-tempf) || (ans == abs(t-tempf) && temp < moves)) {
        moves = temp;
        ans = tempf;
    }
    return moves*2 + 1;
}

void solve() {
    cin >> h >> c >> t;
    if (t <= (h+c)/2) {
        cout << "2\n";
        return;
    }
    if (t >= h) {
        cout << "1\n";
        return;
    }
    double ans = search();
    printf("%.0f\n",ans);

}


int main() {
    ios_base::sync_with_stdio;
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
