#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    ll a;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<ll> v(n);
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }
        unordered_map<ll, int> m;

        int maxl = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            auto it = m.find(v[r]);
            if (it != m.end()) {
                l = max(l, it->second + 1);
                it->second = r;
            }
            else
                m[v[r]] = r;
            maxl = max(maxl, r - l + 1);
        }
        cout << maxl << '\n';
    }
}
