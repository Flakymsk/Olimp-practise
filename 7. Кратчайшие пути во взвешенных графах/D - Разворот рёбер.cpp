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

    int n, m, s, f, v1, v2;
    ll w;
    cin >> n >> m >> s >> f;
    vector<vector<pair<int, int>>> v(n+1);
    vector<ll> ans(n+1, inf);

    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2;
        v[v1].push_back({v2, 0});
        v[v2].push_back({v1, 1});
    }

    deque<int> dq;

    ans[s] = 0;
    dq.push_back(s);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        if (cur == f) break;

        for (auto& ver : v[cur]) {
            int to = ver.first;
            int weight = ver.second;

            if (ans[cur] + weight < ans[to]) {
                ans[to] = ans[cur] + weight;
                if (weight == 0) {
                    dq.push_front(to);
                } else {
                    dq.push_back(to);
                }
            }
        }
    }
    if (ans[f] == inf)
        cout << -1;
    else
        cout << ans[f];
}
