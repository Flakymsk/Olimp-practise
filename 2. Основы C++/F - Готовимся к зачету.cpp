#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a, max1, max2, val, p = 125;
    cin >> n >> a;
    max1 = a * 5 % mod;
    max2 = a * 25 % mod;
    if (max1 > max2) swap(max1, max2);

    for (ll i = 2; i < n; ++i) {
        val = a * p % mod;
        p = p * 5 % mod;
        if (val > max2) {
            max1 = max2;
            max2 = val;
        }
        else if (val > max1) {
            max1 = val;
        }
    }
    cout << max1 << ' ' << max2;
}
