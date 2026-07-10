#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, l, r, v;
    cin >> n >> q;
    if (n == 0) return 0;
    vector<ll> a(n+2);
    for (int i = 0; i < q; ++i) {
        cin >> l >> r >> v;
        a[l] += v;
        a[r+1] -= v;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += a[i];
        cout << ans << ' ';
    }

}
