#include <bits/stdc++.h>

using namespace std;

int const MAX = 200001;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] << "\n";
        return 0;
    }
    long long ans = 1;
    for(int i = 2;  i*i < MAX;) {
        int cont = 0;
        for(int j =  0; j < n; j++) {
            if (a[j] % i == 0) {
                cont++;
                a[j]/=i;
            }
        }
        if (cont >= n - 1) {
            ans *= i;
        } else {
            for(int j = 0; j < n;j++) {
                while (a[j]%i == 0) {
                    a[j]/=i;
                }
            }
            i++;
        }
    }
    vector<int> freq (MAX,0);
    for(int i = 0; i < n; i++) {
        freq[a[i]] ++;
    }
    for(int i = 0; i < MAX; i++) {
        if (freq[i] >= n - 1)  {
            ans *= i;
        }
    }


    cout << ans << "\n";
}
