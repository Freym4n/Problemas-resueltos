
#include <bits/stdc++.h>

using namespace std;

int n,m;

bool up(vector<string> &a, int x, int y) {
    if (y == 0) return false;
    if (x == 0 || x == m) return true;
    if (a[y][x-1] == '/' && a[y][x] == 92) return false;
    if (a[y-1][x-1] == 92 && a[y-1][x] == '/') return false;
    if (a[y-1][x-1] == 92 && a[y][x] == 92) return false;
    if (a[y][x-1] == '/' && a[y-1][x] == '/') return false;
    return true;
}

bool down(vector<string> &a, int x, int y) {
    if (y == n) return false;
    if (x == 0 || x == m) return true;
    if (a[y+1][x-1] == '/' && a[y+1][x] == 92) return false;
    if (a[y][x-1] == 92 && a[y][x] == '/') return false;
    if (a[y][x-1] == 92 && a[y+1][x] == 92) return false;
    if (a[y+1][x-1] == '/' && a[y][x] == '/') return false;
    return true;
}

bool left(vector<string> &a, int x, int  y) {
    if (x == 0) return false;
    if (a[y][x-1] != '.') return false;
    return true;
}

bool right(vector<string> &a, int x, int  y) {
    if (x == m) return false;
    if (a[y][x] == '.') return true;
    return false;
}

bool is_ok(int x, int y) {
    return x >= 0 && x <= m && y >= 0 && y <= n;
}

void bfs(vector<string> &a, int y1, int x1, vector<vector<int> > &v, int cont) {
    queue<pair<int,int> > q;
    q.push({y1,x1});
    v[y1][x1] = cont;
    while(!q.empty()) {
        pair<int,int> t = q.front();
        q.pop();
        int y = t.first;
        int x = t.second;
        if (is_ok(x,y-1) && !v[y-1][x] && up(a,x,y)) {
            v[y-1][x] = cont;
            q.push({y-1,x});

        }
        if (is_ok(x+1,y) && !v[y][x+1] && right(a,x,y)) {
            v[y][x+1] = cont;
            q.push({y,x+1});
        }
        if (is_ok(x,y+1) && !v[y+1][x] && down(a,x,y)) {
            v[y+1][x] = cont;
            q.push({y+1,x});
        }
        if (is_ok(x-1,y) && !v[y][x-1] && left(a,x,y)) {
            v[y][x-1] = cont;
            q.push({y,x-1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<string> a;
    string first (m+1,'.');
    a.push_back(first);
    for(int i = 0; i < n; i++) {
        string in;
        cin >> in;
        in.push_back('.');
        a.push_back(in);
    }
    string last (m+1,'.');
    a.push_back(last);
    n++;
    vector<vector<int> > v;
    for(int i = 0; i <= n; i++) {
        v.push_back(vector<int> (m+1,0));
    }
    int cont = 0;
    for(int y = 0; y <= n; y++) {
        for(int x = 0; x <= m; x++) {
            if (v[y][x]) continue;
            bfs(a,y,x,v,++cont);
        }
    }
    cout << cont-1<< "\n";



}

