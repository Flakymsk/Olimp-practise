#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, num = 0, m;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                m = max(max(arr[i], arr[j]), arr[k]);
                if (m == arr[i])
                    if ( m < arr[j] + arr[k])
                        ++num;
                if (m == arr[j] && arr[i] != arr[j])
                    if ( m < arr[i] + arr[k])
                        ++num;
                if (m == arr[k] && arr[i] != arr[k] && arr[j] != arr[k])
                    if ( m < arr[j] + arr[i])
                        ++num;
            }
        }
    }
    cout << num;
}
