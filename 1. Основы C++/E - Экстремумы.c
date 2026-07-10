#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, gmin, gmax;
    cin >> n;
    vector<int> arr(n);
    vector<int> mins;
    vector<int> maxs;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    gmin = 1;
    int gminn = arr[0];
    gmax = 1;
    int gmaxn = arr[0];
 
    if (arr.size() == 1) {
        mins.push_back(1);
        maxs.push_back(1);
    }
    else if (arr[0] < arr[1])
        mins.push_back(1);
    else if (arr[0] > arr[1])
        maxs.push_back(1);
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            mins.push_back(i+1);
            if (arr[i] < gminn) {gmin = i + 1; gminn = arr[i];}
        }
 
        else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            maxs.push_back(i+1);
            if (arr[i] > gmaxn) {gmax = i + 1; gmaxn = arr[i];}
        }
    }
    if (arr.size() == 1)
        n = n;
    else if (arr[n - 2] > arr[n - 1]) {
        mins.push_back(n);
        if (arr[n - 1] < gminn) gmin = n;
    }
 
    else if (arr[n - 2] < arr[n - 1]) {
        maxs.push_back(n);
        if (arr[n - 1] > gmaxn) gmax = n;
    }
    cout << mins.size() << ' ';
    for (int i = 0; i < mins.size(); ++i) {
        cout << mins[i] << ' ';
    }
    cout << '\n';
    cout << maxs.size() << ' ';
    for (int i = 0; i < maxs.size(); ++i) {
        cout << maxs[i] << ' ';
    }
    cout << '\n';
    cout << gmin << ' ' << gmax;
}
