#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;

ll binpow(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    ll res = 1;
    map<char, int> l;
    for (char c : s) {
        ++l[c];
    }
    ll f = 1;
    for (int i = 1; i <= s.size(); ++i) {
        f = f * i % mod;
    }

    ll znam = 1;
    for (auto [c, num] : l) {
        ll cur_znam = 1;
        for (int i = 1; i <= num; ++i) {
            cur_znam = cur_znam * i % mod;
        }
        znam = znam * cur_znam % mod;
    }
    cout << f * binpow(znam, mod - 2) % mod;
}
