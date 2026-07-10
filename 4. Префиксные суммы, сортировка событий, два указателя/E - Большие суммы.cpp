#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a;
    ll sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        sum = (sum + a + mod) % mod;
    }
    ll p = 1;
    for (int i = 0; i < n - 1; ++i)
        p = p * 2 % mod;
    cout << sum * p % mod;
}
