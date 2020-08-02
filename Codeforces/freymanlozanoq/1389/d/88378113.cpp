#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n; long long k;
    cin >> n >> k;
    int al,ar,bl,br;
    cin >> al >> ar >> bl >> br;
    int idx = 0;
    long long steps= 0;
    long long already = 0;
    if (ar > bl && br > al) {
        already = min(ar,br) - max(al,bl);
    }
    k -= already*n;
    if (k <= 0) {
        cout << "0\n";
        return;
    }
    long long min_union = 0;
    long long max_inter = max(ar,br) - min(al,bl);
    if (ar < bl) {
        min_union = bl - ar;
    } else if (br < al) {
        min_union = al - br;
    }
    steps += min_union;
    bool into = true;
    while(idx < n && k) {
        if(into) {
            long long max_g = min(k,max_inter - already);
            steps += max_g;
            k -= max_g;
            if (min_union + min(k,max_inter - already) < min(k,max_inter - already)*2 && max_g > 0 && idx < n - 1) {
                steps += min_union;
                idx++;
            } else {
                into = false;
            }

        } else {
            steps += k*2;
            k = 0;
            break;
        }
    }
    if (k>0) steps += k*2;
    cout << steps << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) solve();
    //solve();

}
