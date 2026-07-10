#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, k, v1, v2;
    cin >> n >> m >> k;
    vector<vector<int>> v(n+1);
    vector<int> dist(n+1, -1);
    queue<int> q;
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    q.push(k);
    dist[k] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int to : v[cur]) {
            if (dist[to] == -1) {
                dist[to] = dist[cur] + 1;
                q.push(to);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << ' ';
    }
}
