#include <bits/stdc++.h>

using namespace std;

struct Query {
	int x,i,cont;

public:
	Query(int cont1, int x1, int i1);
};

Query::Query(int cont1, int x1, int i1) {
	x = x1;
	i = i1;
	cont = cont1;
}

int const NMAX = 300000;
int bit[NMAX];
int n,k;
int last_delete[NMAX];
queue<Query> q;

void add(int i, int v) {
		bit[i] += v;
}

static int query(int i ) {
	return bit[i];
}

int clear(int i) {
	int sum = query(i);
	add(i,-sum);
	return sum;
}

int read_first(int r) {
	int result = 0;
	while(!q.empty() && q.front().cont <= r) {
		if (last_delete[q.front().x] <= q.front().i){
			result ++;
			add(q.front().x, -1);
			q.pop();
		} else q.pop();
	} return result;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int temp, cont = 0, type,x,result = 0;
	for(int i = 0; i < k; i++) {
		cin >> type >> x;
		x--;
		if (type == 1) {

			cont ++;
			result ++;
			add(x,1);
			Query q1(cont,x,i);
			q.push(q1);
		} else if (type == 2) {
			temp = clear(x);
			result -= temp;
			last_delete[x] = i;
		} else {
			temp = read_first(x + 1);
			result -= temp;
		}
		cout << result << "\n";
	}
	return 0;
}
