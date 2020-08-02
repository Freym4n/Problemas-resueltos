#include <bits/stdc++.h>

using namespace std;


int bin_search(int low, int x, vector<int> &v) {
    int high = v.size()-1;
    int mid = 0;
    int best_option = v.size();
    while(low <= high) {
        mid = low + (high - low)/2;
        if (v[mid] >= x) {
            best_option = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return best_option;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> t (n), s (n), dif(n);
    for(int i = 0; i <n; i++) cin >> t[i];
    for(int i = 0; i <n; i++) cin >> s[i];
    for(int i = 0; i <n; i++) dif[i] = t[i] - s[i];
    sort(dif.begin(),dif.end());
    long long sum = 0;
    for(int i = 0; i <n-1; i++) {
        int value = 1 - dif[i];
        int index = bin_search(i+1,value,dif);
        //n-index
        sum += n - index;
    }
    cout << sum << "\n";


}
