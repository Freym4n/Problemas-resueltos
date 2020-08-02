#include <bits/stdc++.h>

using namespace std;

string dp[1000][1000];

string get_max(string a, string b) {
	int al = a.length();
	int bl = b.length();
	if (al > bl) return a;
	else if (al < bl) return b;
	else  {
		int d = a.compare(b);
		if (d <  0) return a;
		else return b;
	}
}

string solve(string s) {
	int n = s.length();
	for(int i = 0; i < n; i++)
		dp[i][i] = s[i];
	for(int i = 0; i < n - 1 ; i++) {
		if (s[i] == s[i+1])
			dp[i][i+1] = s.substr(i,2);
		else
			dp[i][i+1] = get_max(s.substr(i,1),s.substr(i+1,1));
	}
	string t;
	for(int l = n -1; l >= 0; l--) {
		for(int r = l + 2; r < n; r++ ) {
			if (s[l] == s[r]){
				t = s[l] + dp[l+1][r-1] + s[r];
			}
			else
				t.clear();
			t = get_max(t, dp[l][r-1]);
			t = get_max(t, dp[l+1][r]);
			dp[l][r] = t;
		}
	}
	return dp[0][n-1];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	string s;
	while(cin >> s) {
		cout << solve(s) << "\n";
	}
return 0;
}
