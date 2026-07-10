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
    vector<bool> visited(n+1);
    vector<int> path;
    for (int i = 1; i <= m; ++i) {
        cin >> v1 >> v2;
        vv[v1].push_back(v2);
        vv[v2].push_back(v1);
    }

    bool found = dfs(vv, u, v, visited, path);

    if (!found) {
        cout << -1;
    }
    else {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << ' ';
        }
    }

}
