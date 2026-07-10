#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, l, r, j;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        cin >> j;
        arr.push_back(j);
    }
 
    while (cin >> l >> r && l != 0 && r != 0) {
        --l;
        --r;
        for (int i = 0; i <= (r - l) / 2; ++i) {
            j = arr[i + l];
            arr[i + l] = arr[r - i];
            arr[r - i] = j;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
 
