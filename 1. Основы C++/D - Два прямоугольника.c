#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int s = abs((x1 - x2) * (y1 - y2)) + abs((x3 - x4) * (y3 - y4));
    int minx1 = min(x1, x2), minx2 = min(x3, x4), maxx1 = max(x1, x2), maxx2 = max(x3, x4);
    int l = max(minx1,minx2);
    int r = min(maxx1, maxx2);
    int w = max(r-l, 0);
    int miny1 = min(y1, y2), miny2 = min(y3, y4), maxy1 = max(y1, y2), maxy2 = max(y3, y4);
    int b = max(miny1,miny2);
    int t = min(maxy1, maxy2);
    int h = max(t-b, 0);
    s -= h*w;
    cout << s;
}
