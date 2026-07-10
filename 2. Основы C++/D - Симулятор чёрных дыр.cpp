#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    ll val1, val2, sum = 0;
    cin >> n >> val1;
    vector<pair<int, int>> v(n);
    vector<int> vv;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second;
        v[i].first = i;
    }
    sort(all(v), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });
    for (int i = n - 1; i >= 0; --i) {
        if (val1 > v[i].second) {
            val1 += v[i].second;
            vv.push_back(v[i].first+1);
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << vv[i] << ' ';
    }
}
