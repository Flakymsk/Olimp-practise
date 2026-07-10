#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t, num = 0, n, m;
    cin >> t;
    vector<vector<int>> arr(t);
    for (int i = 0; i < t; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> n;
            arr[i].push_back(n);
        }
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (int j = 0; j < m - 1; ++j) {
                if ( arr[i][j] > arr[i][j+1]) {
                    swap(arr[i][j], arr[i][j+1]);
                    ++num;
                    sorted = false;
                }
            }
        }
        cout << num << '\n';
        num = 0;
    }
}
