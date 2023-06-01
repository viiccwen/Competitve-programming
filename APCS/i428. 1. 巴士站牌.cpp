#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y, xx, yy;
    int maxx = 0, minn = 100000;
    
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        if (i == 1) {
            cin >> x >> y;
            cin >> xx >> yy;
        }
        else {
            x = xx, y = yy;
            cin >> xx >> yy;
        }
        int dis = 0;
        (x - xx >= 0) ? dis += x - xx : dis += xx - x;
        (y - yy >= 0) ? dis += y - yy : dis += yy - y;
        maxx = max(maxx, dis);
        minn = min(minn, dis);
    }
    cout << maxx << ' ' << minn;
    
    return 0;
}
