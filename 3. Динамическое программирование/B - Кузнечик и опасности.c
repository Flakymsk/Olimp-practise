#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m, mm;
    cin >> n >> k >> m;
    vector<bool> v(n + 1);
    vector<ll> a(n + 1);
    a[0] = 1;
    for (int i = 0; i < m; ++i) {
        cin >> mm;
        v[mm] = true;
    }
    ll sum = 1;
    for (int i = 1; i <= n; ++i) {


        if (i > k)
            sum = (sum - a[i - k - 1] + mod) % mod;

        if (v[i]) {
            a[i] = 0;
        }
        else
            a[i] = sum;

        sum = (sum + a[i]) % mod;
    }
    cout << a[n];

}
