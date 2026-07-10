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

    int n, m, v1, v2;
    ll w;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> v(n+1);
    vector<ll> dist(n+1, inf);
    vector<int> p(n+1, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2 >> w;
        v[v1].push_back({v2, w});
    }

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto[d, cur] = pq.top();
        pq.pop();

        if (d > dist[cur]) continue;

        for (auto ver : v[cur]) {
            int to = ver.first;
            w = ver.second;

            if (dist[cur] + w < dist[to]) {
                dist[to] = dist[cur] + w;
                p[to] = cur;
                pq.push({dist[to], to});
            }
        }
    }
    if (dist[n] == inf)
        cout << -1;
    else {
        vector<int> path;
        for (int cur = n; cur > -1; cur = p[cur]) {
            path.push_back(cur);
        }
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << ' ';
        }
    }

}
