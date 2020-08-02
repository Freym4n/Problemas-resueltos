/*
 * Main.cpp
 *
 *  Created on: 24/04/2020
 *      Author: freyman
 */

#include <bits/stdc++.h>

using namespace std;
int const inf = 1000000001;
int MAX = 1500;
int N,K;
string cards[1500];
set<string> s;

string gen_card(string a, string b ) {
	string card;
	for(int i = 0; i < K ; i++) {
		if (a[i] == b[i]) {
			card.push_back(a[i]);
		} else {
			if (a[i] == 'S') {
				if (b[i] == 'E') card.push_back('T');
				else card.push_back('E');
			} else if (a[i] == 'T') {
				if (b[i] == 'E') card.push_back('S');
				else card.push_back('E');
			} else {
				if (b[i] == 'S') card.push_back('T');
				else card.push_back('S');
			}
		}
	} return card;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	string str;
	for(int i = 0; i < N ; i++) {
		cin >> str;
		cards[i] = str;
		s.insert(str);
	}
	int ans = 0;
	for(int i = 0; i < N-1; i++) {
		for(int j = i + 1; j < N ; j++) {
			string new_card = gen_card(cards[i],cards[j]);

			//cout << new_card << " " << cards[i] << " " << cards[j] << "\n";
			if (s.count(new_card)) ans++;
		}
	} cout << ans/3 << "\n";


}


