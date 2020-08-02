
#include <bits/stdc++.h>

using namespace std;



 int const n = 200000;
 int parent[n];
 int sizeN[n];
 int p[n];

 void make_set(int value) {
	parent[value] = value;
	sizeN[value] = 1;
}

 int find_set(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find_set(parent[node]);
}

 bool union_set(int a, int b) {
	int pa = find_set(a);
	int pb = find_set(b);
	if (pa == pb)  return true;
	parent[pa] = pb;
	sizeN[pb] += sizeN[pa];
	return false;
}

 void solve(int m) {
	for (int i = 0; i < m; i++)
		make_set(i);
	for (int i = 0; i < m; i++)
		union_set(i, p[i]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cases,tam;
	cin >> cases;
	for(int i = 0; i < cases; i++) {
		cin >> tam;
		for(int j = 0; j < tam; j++) {
			cin >> p[j];
			p[j] --;
		}
		solve(tam);
		for(int j = 0; j < tam; j ++){
			cout << sizeN[find_set(j)];
			if (j <  n - 1) cout << " ";
		} cout << "\n";

	}
	return 0;
}



