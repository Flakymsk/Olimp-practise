#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
using graph = vector<vector<int>>;
ll mod = 1e9+7;

bool dfs(graph& g, int cur, int v, vector<bool>& visited, vector<int>& path) {
    visited[cur] = true;
    path.push_back(cur);

    if (cur == v) return true;

    for (int to : g[cur]) {
        if (!visited[to])
            if (dfs(g, to, v, visited, path)) return true;
    }
    path.pop_back();
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, u, v, v1, v2;
    cin >> n >> m >> u >> v;
    vector<vector<int>> vv(n+1);
    vector<int> p(n+1);
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> v1 >> v2;
        vv[v1].push_back(v2);
        vv[v2].push_back(v1);
    }

    for (int i = 1; i <= n; ++i) {
        sort(all(vv[i]));
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int to : vv[cur]) {
            if (dist[to] == -1) {
                dist[to] = dist[cur] + 1;
                p[to] = cur;
                q.push(to);
            }
        }
    }
    if (dist[v] == -1)
        cout << -1;
    else {
        vector<int> path;
        for (int i = v; i != 0; i = p[i])
            path.push_back(i);
        reverse(all(path));
        for (int i = 0; i < path.size(); ++i)
            cout << path[i] << ' ';
    }
}
