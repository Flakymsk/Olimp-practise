#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll f = 0, sum = 0;
    string s;
    while (cin >> s){
        int i = 0;
        while (s[i] != '.') ++i;
        sum += stoll(s.substr(0, i));
        ++i;
        f += stoll(s.substr(i, 15));
        if (f >= 1'000'000'000'000'000LL) {
            ++sum;
            f -= 1'000'000'000'000'000LL;
        }
    }
    ll len = (f == 0) ? 1 : static_cast<ll>(log10(f)) + 1;
    len = 15 - len;
    s = "";
    for (int i = 0; i < len; ++i)
        s.append("0");
    cout << sum << '.' << s << f;
}
