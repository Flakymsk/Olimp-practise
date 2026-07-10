
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
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(all(v));
    for (int i = n - 1; i >= 2; --i) {
        int j = 0;
        int k = i - 1;
        while (j < k) {
            if (v[j] + v[k] > v[i]) {
                sum += k - j;
                --k;
            }
            else
                ++j;
        }
    }
    cout << sum;
}
