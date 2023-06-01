#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    ull int x, y, layer, max_num;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        layer = max(x, y);
        max_num = layer * layer;
        
        if (layer % 2 == 1) { // 單數 maximum = layer * layer 位置 = (1, layer)
            if (y == layer) cout << max_num - (x - 1);
            else cout << max_num - (layer - 1) - (layer - y);
        }
        else { // 單數 maximum = layer * layer 位置 = (layer, 1)
            if (x == layer) cout << max_num - (y - 1);
            else cout << max_num - (layer - 1) - (layer - x);
        }

        cout << '\n';
    }
}
// 假設target (x,y)
// 取 max(x, y) 就是(x,y)所屬的層數 假設為 t
// 該 t 層最大數字為 t*t 假設為 maximum
// 接著判斷 單數層 偶數層 

// 若是單數 則是由左下開始往右再往上遞增
// 若 y = layer (在相同column上)
// 則只需 maximum - (target.x - maximum.x) // maximum.x 為 1
// 否則 maximum - (layer - 1) - (layer - y) // maximum - column - row

// 若是偶數 則是由右上開始往下在我左遞增
// 若 x = layer (在相同row上)
// 則只需 maximum - (target.y - maximum.y) // maximum.y 為 1
// 否則 maximum - (layer - 1) - (layer - x) // maximum - row - column