#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, buy = -1, sell = -1;
    ll a, sum = 0, cur, minp = 0, minptime = 0, maxprofit = 0;
    cin >> n;
    //vector<ll> v(n+1);
    vector<ll> vv(n+1);
    for (int i = 1; i <= n; ++i){
        cin >> a;
        vv[i] = a + vv[i-1];
    }
    for (int i = 1; i <= n; ++i) {
        cur = vv[i] - minp;
        if (cur > maxprofit) {
            maxprofit = cur;
            sell = i;
            buy = minptime;
        }
        if (minp > vv[i]) {
            minp = vv[i];
            minptime = i;
        }
    }
    maxprofit > 0 ? cout << buy + 1 << ' ' << sell + 1 : cout << -1 << ' ' << -1;
}
