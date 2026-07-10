#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) begin(x), end(x)
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, num ;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (!s.insert(num).second){ cout << "Scammed"; return 0;}
    }
    auto it = s.begin();
    for (int i = 0; i < n - 1; ++i) {
        if (*it + 1 != *(++it)){ cout << "Scammed"; return 0;}
    }
    cout << "Deck looks good";
}
