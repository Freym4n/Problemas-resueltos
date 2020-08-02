
#include <bits/stdc++.h>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */
int MAX = 1001;
int n,x;
vector< vector <int>> lst(MAX);

void solve() {
    cin >>n >> x;
    x--;
    for(int i = 0; i < n; i++) {
        lst[i].clear();
    }
    int from,to;
    for(int i = 0; i< n-1;i++) {
        cin >> from >> to;
        lst[from-1].push_back(to-1);
        lst[to-1].push_back(from-1);
    }
    vector<int> dist(n,0);
    vector<int> parent(n,0);
    vector<int> deg(n,0);
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        for(int i:lst[temp]) {
            if (dist[i] == 0 && i != x) {
                parent[i] = temp;
                dist[i] = dist[temp] + 1;
                q.push(i);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        deg[i] = lst[i].size();
    }
    int moves = 0;
    bool winner = false;
    while(!winner) {
        if (deg[x] <= 1) {
            winner = true;
            break;
        }
        int idx = -1;
        int depth = -1;
        for(int i= 0; i <n; i++) {
            if (deg[i] != -1 && deg[i] <= 1) {
                if (dist[i]%2 == 0 && (depth %2 == 1 || dist[i] < depth)) {
                    idx = i;
                    depth = dist[i];
                } else {
                    if (depth%2 == 0) continue;
                    if (dist[i] > depth) {
                        idx = i;
                        depth = dist[i];
                    }
                }
            }
        }
        deg[idx] = -1;
        deg[parent[idx]] --;
        moves++;
    }
    if (moves%2 == 0) {
        cout << "Ayush\n";
    } else {
        cout << "Ashish\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
