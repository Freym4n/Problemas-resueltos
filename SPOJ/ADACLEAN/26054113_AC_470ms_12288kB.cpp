
#include <bits/stdc++.h>

using namespace std;

// string T
// string s
//cuantas veces está s en t
// O (n + m)

// comparar strings en O(1)
//

// fuerza bruta
//aaaaaaaaaaaaaaaaaaaaaa
//aaaa
// O(n*n)
// MAX_N = 5000


//hashing
// O(n)
//MAX_N = 10000000

//cesar h(cesar) = 50
//cristian h(cristian) = 56

//n1*2**0 + n1*2**1 +  n3*2**2     n1 = 1 n2 = 0 n3 = 1
//a = 1
//b = 2
//z = 26

//string s len = 10
//s[i]
//h(s) = s[0]*p**0 + s[1]*p**1 + .... s[n-1]*p**(n-1)




//p = 31
// 26**9
// mod 1000000007
//probabilidad de colisión con dos hash = 1 * 10**(-18)

//acaba
//h(acaba) = a*31**0  + c*31**1 + a*31**2 + b*31**3 + a*31**4
//b*31**3 + a*31**4 / 31**3
//= b*31**0 + a*31**1
//ac ca ab ba

//acab + a*p**a

vector<pair<long long, long long>> gen_hash(string s, int l ) {
    int n = s.size();
    long long p = 31;
    long long mod = 1000000009;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for(int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i-1] * p)%mod;
    }
    vector<long long> h (n+1,0);
    for(int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) %mod;
    }

    //hash 2
    long long p1 = 53;
    long long mod1 = 1000000007;
    vector<long long> p_pow1(n);
    p_pow1[0] = 1;
    for(int i = 1; i < n; i++) {
        p_pow1[i] = (p_pow1[i-1] * p1)%mod1;
    }
    vector<long long> h1 (n+1,0);
    for(int i = 0; i < n; i++) {
        h1[i+1] = (h1[i] + (s[i] - 'a' + 1) * p_pow1[i]) %mod1;
    }

    vector<pair<long long, long long>> hashes;
    for(int i = 0; i <= n - l ; i++) {
        long long hi = (h[i+l]  - h[i] + mod)%mod;
        hi = (hi * p_pow[n-i-1]) % mod;
        long long hi1 = (h1[i+l]  - h1[i] + mod1)%mod1;
        hi1 = (hi1 * p_pow1[n-i-1]) % mod1;
        hashes.push_back({hi,hi1});
    }
    return hashes;
}

//asbvcsfgfdfg
// l = 4
//{34,66,9798,887,8789}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n,l;
        cin >> n >> l;
        string s;
        cin >> s;
        vector<pair<long long, long long>> hashes = gen_hash(s,l);
        set<pair<long long, long long >> ans;
        for(int i = 0; i < hashes.size(); i++) {
            ans.insert(hashes[i]);
        }
        cout << ans.size() << "\n";
    }
}

