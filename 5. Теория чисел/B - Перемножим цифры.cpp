#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<ll> v(t);

    for (int i = 0; i < t; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < t; ++i) {
        if (v[i] == 0) {cout << 10 << '\n'; continue;}
        if (v[i] == 1) {cout << 1 << '\n'; continue;}
        string res = "";
        for (int j = 9; j > 1; --j) {
            while (v[i] % j == 0) {
                res += to_string(j);
                v[i] /= j;
            }
        }
        reverse(all(res));
        if (v[i] > 1) {
            cout << -1 << '\n';
        }
        else cout << res << '\n';

    }
}
