
#include <bits/stdc++.h>

using namespace std;

bool is_max(pair<int,int> a, pair<int,int> b) {
    if (b.first > a.first || (b.first == a.first && b.second > a.second)) {
        return false;
    } return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
       string s;
       cin >> s;
       int n = s.size();
       set< pair<pair< int,int >,pair< int,int > > > se;
       int x = 0, y = 0,x1,y1;
       int ans = 0;
       for(int i = 0; i < n; i++) {
            x1 = x;
            y1 = y;
            if (s[i] == 'N') {
                y1++;
            } else if (s[i] ==  'S')  {
                y1--;
            } else if ( s[i] == 'W') {
                x1--;
            } else {
                x1++;
            }
            pair<int,int> current, next;
            current = {x,y};
            next = {x1,y1};

            pair<pair<int,int>,pair<int,int> > path;
            if (is_max(current,next)) {
                path = {current,next};
            } else  {
                path = {next,current};
            }
            if (se.count(path) > 0 ) {
                ans ++;
            } else {
                se.insert(path);
                ans += 5;
            }
            x = x1;
            y = y1;
       }
       cout << ans << "\n";

	}
	return 0;

}
