#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num, med, val1;
    ll val2, sum = 0;
    cin >> n;
    //vector<int> v(n);
    priority_queue<int> maxv;
    priority_queue<int, vector<int>, greater<int>> minv;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (maxv.empty() || num <= maxv.top()) {
            maxv.push(num);
        } else {
            minv.push(num);
        }
        if (maxv.size() > minv.size() + 1) {
            minv.push(maxv.top());
            maxv.pop();
        }  else if (minv.size() > maxv.size()) {
            maxv.push(minv.top());
            minv.pop();
        }
        if (maxv.size() >= minv.size()) {
            cout << maxv.top() << '\n';
        }
        else {
            cout << minv.top() << '\n';
        }
    }
}
