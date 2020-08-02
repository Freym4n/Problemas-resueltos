
#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long x3,y3,x4,y4;
    cin >> x3 >> y3 >> x4 >> y4;
    long long x5,y5,x6,y6;
    cin >> x5 >> y5 >> x6 >> y6;
    long long area = 0;
    // restamos area intersecta con hoja 1
    long long max_x,min_x,max_y,min_y;
    max_x = min(x2,x4);
    min_x = max(x1,x3);
    max_y = min(y2,y4);
    min_y = max(y1,y3);
    if (max_x > min_x && max_y > min_y)
        area += (max_x - min_x)*(max_y-min_y);
    // restamos area intersecta con hoja 2
    max_x = min(x2,x6);
    min_x = max(x1,x5);
    max_y = min(y2,y6);
    min_y = max(y1,y5);
    if (max_x > min_x && max_y > min_y)
        area += (max_x - min_x)*(max_y-min_y);
    // sumamos area intersecta con hoja 1,2 y blanca
    // primero intersecto entre hoja 1 y 2
    max_x = min(x4,x6);
    min_x = max(x3,x5);
    max_y = min(y4,y6);
    min_y = max(y3,y5);
    if (max_x > min_x && max_y > min_y) {
        long long max_x1 = min(x2,max_x);
        long long min_x1 = max(x1,min_x);
        long long max_y1 = min(y2,max_y);
        long long min_y1 = max(y1,min_y);
        if (max_x1 > min_x1 && max_y1 > min_y1)
            area -= (max_x1 - min_x1) *(max_y1 - min_y1);
    }
    long long area_sheet = (x2 - x1) * (y2 - y1);
    area_sheet -= area;
    if (area_sheet > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();



}

