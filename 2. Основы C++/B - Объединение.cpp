
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, num;
    ll val1, val2;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        q.push(num);
    }
    while (q.size() > 1) {
        val1 = q.top();
        q.pop();
        val2 = q.top();
        q.pop();
        q.push(val1 + val2);
        cout << val1 << ' ' << val2 << '\n';
    }
}
