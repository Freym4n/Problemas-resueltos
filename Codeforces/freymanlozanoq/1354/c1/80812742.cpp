#include <bits/stdc++.h>
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        double n;
        cin >> n;
        double angle = (2.0*M_PI)/(4.0*n);
        double ans = 1.0/(tan(angle));
        printf("%.7f\n",ans);
    }
}
