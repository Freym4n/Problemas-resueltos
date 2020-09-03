#include <bits/stdc++.h>

using namespace std;

int const MAX_N = 50001;
vector<int> lst[MAX_N], lstr [MAX_N];
vector<int> order;
bool visited[MAX_N];
int component[MAX_N];

void dfs1(int node) {
    visited[node] = 1;
    for(int v: lst[node]) if (!visited[v]) {
        dfs1(v);
    }
    order.push_back(node);
}

void dfs2(int node, int p) {
    component[node] = p;
    visited[node] = 1;
    for(int v: lstr[node]) if (!visited[v]) {
        dfs2(v,p);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,type,to,from;
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++) {
            lst[i].clear();
            lstr[i].clear();
            visited[i] = 0;
        }
        for(int i = 0; i < m;i++) {
            cin >> type;
            if (type == 1) {
                cin >> from >> to;
                --from; --to;
                lst[from].push_back(to);
                lstr[to].push_back(from);
            } else {
                cin >> from;
                --from;
                --type;
                while(type--) {
                    cin >> to;
                    --to;
                    lst[from].push_back(to);
                    lst[to].push_back(from);
                    lstr[from].push_back(to);
                    lstr[to].push_back(from);
                }
            }
        }
        order.clear();
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i);
            }
        }
        for(int i = 0; i < n; i++) visited[i] = 0;
        int p = 1;
        for(int i = n - 1; i >= 0; i--) {
            if (!visited[order[i]]) {
                dfs2(order[i],p++);
            }
        }
        if(p == 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}






