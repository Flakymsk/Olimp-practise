#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll nod = v[0];
    for (int i = 1; i < n; ++i) {
        nod = nod / gcd(nod, v[i]) * v[i];
    }
    cout << nod;
}
