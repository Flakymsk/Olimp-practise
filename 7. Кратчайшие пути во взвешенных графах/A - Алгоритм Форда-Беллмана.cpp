#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;
const ll inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, v1, v2;
    ll w;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> v(n+1);
    vector<ll> ans(n+1, inf);

    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2 >> w;
        v[v1].push_back({v2,w});
    }

    bool done = false;
    bool better = false;
    ans[s] = 0;
    int iter = 0;
    bool negcycle = false;

    while (!done) {
        better = false;
        ++iter;

        if (iter > n) {
            negcycle = true;
            break;
        }

        for (int i = 1; i <= n; ++i) {
            if (ans[i] == inf) continue;

            for (auto ver : v[i]) {
                int to = ver.first;
                w = ver.second;

                if (ans[i] + w < ans[to]) {
                    ans[to] = ans[i] + w;
                    better = true;
                }
            }
        }
        if (!better)
            done = true;
    }
    if (negcycle)
        cout << "Negative cycle";
    else {
        for (int i = 1; i <= n; ++i) {
            if (ans[i] == inf) {
                cout << "inf" << ' ';
            } else {
                cout << ans[i] << ' ';
            }
        }
    }
}
