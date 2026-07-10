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
 
    ll n, k;
    ll dist = 0;
    cin >> n >> k;
    ll iter = 1;
    ll cap = n * 4;
    ll count;
    while (k > 0) {
        count = min(cap, k);
        dist += count * iter;
        k -= count;
        ++iter;
        cap += 4;
    }
    cout << dist;
}
