#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
ll mod = 1e9+7;

ll binpow(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    int ogr = 4*1e7 + 1;
    vector<bool> vb(ogr, true);

    vector<int> v;
    for (int i = 2; i*i <= ogr; ++i) {
        if (vb[i]) {
            for (int j = i*i; j <= ogr; j += i)
                vb[j] = false;
        }
    }
    for (int i = 2; i < ogr; ++i) {
        if (vb[i] == true)
            v.push_back(i);
    }
    for (int i = 0; i < t; ++i) {
        cin >> n;
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        if (vb[n]) {
            cout << "Prime\n";
            continue;
        }
        ll sum = 0;
        int temp = n;
        for (int j = 0; j < v.size() && (ll)v[j] * v[j] <= temp; ++j) {
            if (temp % v[j] == 0) {
                ++sum;
                while (temp % v[j] == 0) {
                    temp /= v[j];
                }
            }
        }
        if (temp > 1) ++sum;
        cout << sum << '\n';
    }
}
