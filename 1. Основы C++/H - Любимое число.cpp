#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ull n, k;
    cin >> n >> k;
    if (1ULL << k > n) {
        cout << -1;
        return 0;;
    }
    ull a = (~0ULL << k) & n;
    if (!(a >> k & 1)){
        a -= 1ULL << k;
        a &= ~0ULL << k;
    }
    cout << a;
}
