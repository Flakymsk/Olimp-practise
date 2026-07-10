#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> b(n, vector<ll>(m));

    ll ga = 0, gb = 0, gc = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ga = gb = gc = 0;
            if (i > 0) {
                ga = b[i-1][j];
            }
            if (j > 0) {
                gb = b[i][j-1];
            }
            if (i > 0 && j > 0) {
                gc = b[i-1][j-1];
            }
            b[i][j] = max(ga, max(gb,gc)) + a[i][j];
        }
    }
    cout << b[n-1][m-1];
}
