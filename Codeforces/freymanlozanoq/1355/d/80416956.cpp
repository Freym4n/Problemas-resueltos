#include <bits/stdc++.h>

using namespace std;



void solve() {
  int n,s;
  cin >> n >> s;
  vector<int> v (n);
  for(int i = 0; i < n -1 ; i++) {
    v[i] = 1;
  }
  v[n-1] = s - (n-1);
  int low = n - 1;
  int high = s - (n - 1);
  if (low >= high -1 ) cout << "NO\n";
  else  {
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cout << v[i];
        if(i < n -1) cout << " ";
    }
    cout << "\n";
    cout << n << "\n";
  }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();


}
