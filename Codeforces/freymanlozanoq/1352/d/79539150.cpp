
#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int moves = 0 ,a = 0,b = 0;
        int  l = 0, r = n - 1;
        int previous = 0, current = 0;
        while (l <= r) {
            current = 0;
            if (moves%2 == 0) {
                while (l <= r && current <= previous) {
                        a += arr[l];
                        current += arr[l];
                        l++;
                    }
            } else {
                while(l <= r && current <= previous) {
                    b += arr[r];
                    current += arr[r];
                    r--;
                }
            }
            moves++;
            previous = current;
        }
        cout << moves << " " << a << " " << b << "\n";


    }

}
