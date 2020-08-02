#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> caso_uno;
    vector<int> caso_dos;
    for(int i = 0; i <n; i++) {
        if (s1[i] == s2[i]) continue;
        if (s1[i] < s2[i]) caso_uno.push_back(i+1);
        else caso_dos.push_back(i+1);
    }
    int len1 = caso_uno.size() ,len2 = caso_dos.size();
    if (((len1 + len2)&1)) {
        cout << "-1\n";
        return 0;
    }
    int pasos = len1/2 + len2/2 + ((len1&1)?2:0);
    cout << pasos << "\n";
    for(int i = 0; i < len1-1; i+=2) {
        cout << caso_uno[i+1] << " " << caso_uno[i] << "\n";
    }
    for(int i = 0; i < len2-1; i+=2) {
        cout << caso_dos[i+1] << " " << caso_dos[i] << "\n";
    }
    if ((len1&1)) {
        cout << caso_uno.back() << " " << caso_uno.back() << "\n";
        cout << caso_uno.back() << " " << caso_dos.back() << "\n";
     }

}
