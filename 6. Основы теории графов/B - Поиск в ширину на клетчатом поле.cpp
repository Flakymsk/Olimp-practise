#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, x, y;
    char v1, v2;
    cin >> n >> m;
    vector<vector<bool>> v(n+1, vector<bool>(m+1, false));
    vector<vector<int>> dist(n+1, vector<int>(m+1, -1));
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v1;
            if (v1 == '.')
                v[i][j] = true;
        }
    }

    cin >> x >> y;
    q.push({x, y});
    dist[x][y] = 0;
    while (!q.empty()) {
        auto [xx, yy] = q.front();
        q.pop();
        if (xx - 1 > 0 && v[xx-1][ yy] == true && dist[xx-1][ yy] == -1) {
            dist[xx - 1][yy] = dist[xx][ yy] + 1;
            q.push({xx - 1, yy});
        }

        if (xx + 1 < n + 1 && v[xx+1][ yy] == true && dist[xx+1][ yy] == -1) {
            dist[xx + 1][yy] = dist[xx][ yy] + 1;
            q.push({xx + 1, yy});
        }

        if (yy - 1 > 0 && v[xx][ yy-1] == true && dist[xx][ yy-1] == -1) {
            dist[xx][yy - 1] = dist[xx][ yy] + 1;
            q.push({xx, yy - 1});
        }

        if (yy + 1 < m + 1 && v[xx][yy+1] == true && dist[xx][ yy+1] == -1) {
            dist[xx][yy + 1] = dist[xx][ yy] + 1;
            q.push({xx, yy + 1});
        }

    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
