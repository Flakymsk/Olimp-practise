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

    int t;
    cin >> t;
    ll b, q ,n;
    for (int i = 0; i < t; ++i) {
        cin >> b >> q >> n;

        if (q == 1) {
            cout << b * n % mod << '\n';
            continue;
        }
        cout << b * ((binpow(q, n) - 1 + mod) % mod) % mod * binpow((q-1+mod)%mod, mod -2) % mod << '\n';
    }

}
