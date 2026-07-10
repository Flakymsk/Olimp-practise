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
    ll sum = 0, cur;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i) {
        cur = v[i];
        for (int j = i; j < n; ++j) {
            cur = max(cur, v[j]);
            sum += cur;
        }
    }
    cout << sum;
}
