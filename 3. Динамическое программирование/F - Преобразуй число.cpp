#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 2; i <= n; ++i) {
        int s = a[i-1] + i;
        if (i % 2 == 0)
            s = min(s, a[i/2] + i);
        if (i % 3 == 0)
            s = min(s, a[i/3] + i);
        a[i] = s;
    }
    cout << a[n];
}
