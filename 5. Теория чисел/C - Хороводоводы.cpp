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

    int n;
    cin >> n;
    ll f = 1;
    for (int i = 1; i < n; ++i) {
        f = f * i % mod;
    }
    cout << f * binpow(2, mod - 2) % mod;
}
