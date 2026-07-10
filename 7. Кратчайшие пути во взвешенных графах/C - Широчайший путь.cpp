#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;
const ll inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, v1, v2, w;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> v(n+1);
    vector<int> ans(n+1, 0 );
    priority_queue<pair<int, int>> pq;
    pq.push({inf, s});
    ans[s] = inf;

    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2 >> w;
        v[v1].push_back({v2, w});
        v[v2].push_back({v1, w});
    }

    while (!pq.empty()) {
        auto [width, cur] = pq.top();
        pq.pop();

        if (width < ans[cur]) continue;

        for (auto ver : v[cur]) {
            int to = ver.first;
            w = ver.second;

            int nextw = min(ans[cur], w);
            if (nextw > ans[to]) {
                ans[to] = nextw;
                pq.push({ans[to], to});
            }

        }
    }

    ans[s] = -1;

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}
