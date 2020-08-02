/*
 * Main.cpp
 *
 *  Created on: 16/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int n;
int const MAX = 200001;
vector< vector <int> > lst;

map <pair<int,int> , int > id;
int result[MAX];
int num = 0;
void dfs(int node, int from) {
	if (lst[node].size() == 1) {
		pair<int,int> temp = make_pair(min(node,lst[node][0]),max(node,lst[node][0]));
		if (result[id[temp]] == -1)result[id[temp]] = num++;
	}
	for(int i = 0; abs(i) < lst[node].size(); i++){
		int to = lst[node][i];
		if (to == from) continue;
		dfs(to,node);
	}
 }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		lst.push_back(vector<int> ());
	}
	int to,from;
	pair<int,int> temp;
	memset(result,-1,sizeof(result));
	for(int i = 0; i < n - 1; i++) {
		cin >> from >> to;
		lst[from-1].push_back(to-1);
		lst[to-1].push_back(from-1);
		temp = make_pair(min(from,to)-1,max(from,to)-1);
		id[temp] = i;
	}
	dfs(0,0);
	for(int i = 0; i<  n - 1 ; i++) {
		if (result[i] != -1) continue;
		result[i] = num++;
	}
	for(int i = 0; i < n -1; i++) {
		cout << result[i] << "\n";
	}
	return 0;
}


