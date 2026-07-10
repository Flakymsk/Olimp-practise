#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r;
    cin >> l >> r;
    ll sum = 0;
    vector<ll> a(r+1);
    a[1] = 1;
    for (int i = 1; i <= r; ++i) {
        if (a[i] == 0) continue;

        for (int j = 2*i; j <= r; j+=i) {
            a[j] = (a[j] + a[i]) % mod;
        }
    }
    for (int i = l; i <= r; ++i) {
        sum = (sum + a[i]) % mod;
    }
    cout << sum;
}
