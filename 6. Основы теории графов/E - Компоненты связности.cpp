#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
using graph = vector<vector<int>>;
ll mod = 1e9+7;

void dfs(graph& g, int cur, vector<bool>& visited) {
    visited[cur] = true;

    for (int to : g[cur]) {
        if (!visited[to])
            dfs(g, to, visited);
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, v1, v2;
    cin >> n >> m;
    graph g(n+1);
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    vector<bool> visited(n+1);
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(g, i, visited);
            ++sum;
        }

    }
    cout << sum;
}
