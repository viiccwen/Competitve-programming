#include <bits/stdc++.h>
using namespace std;

bool myDebug = false;
const int maxn = 105;
int a[maxn][maxn]; //紀錄有幾條線經過（-1/0/1/2），-1表示有木樁
int m, n, h;
int dx[] = {-1, 1, 0, 0}; // 上(0)下(1)左(2)右(3)
int dy[] = {0, 0, -1, 1}; // 上(0)下(1)左(2)右(3)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> m >> n >> h;
    int r, c, t;
    int ans = 0; //最後有線和有木樁佔據空間的面積
    int mx = 0; //操作過程中有線和有木樁佔據空間的面積最大值
    for (int k = 0; k < h; k++) {
        cin >> r >> c >> t;
        //有線經過則先將那些線拆掉
        for (int i = 0; i < 4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];
            bool find = false;
            while (nx >= 0 && nx < m && ny >=0 && ny < n) {
                if (a[nx][ny] == 0) {
                    //沒有線經過
                    break;
                }

                if (a[nx][ny] == -1) {
                    //確定有端點木樁，才不會誤拆了屬於別的木樁的線
                    find = true;
                    break;
                }

                nx += dx[i];
                ny += dy[i];
            }
            if (find) {
                for (int j = min(r, nx)+1; j < max(r, nx); j++) {
                    a[j][ny]--;
                }
                for (int j = min(c, ny)+1; j < max(c, ny); j++) {
                    a[nx][j]--;
                }
            }
        }

        if (t == 0) {
            //加一木樁，然後連線
            a[r][c] = -1;
            for (int i = 0; i < 4; i++) {
                int nx = r + dx[i];
                int ny = c + dy[i];
                bool find = false;
                while (nx >= 0 && nx < m && ny >=0 && ny < n) {
                    if (a[nx][ny] == -1) {
                        find = true;
                        break;
                    }
                    nx += dx[i];
                    ny += dy[i];
                }
                if (find) {
                    for (int j = min(r, nx)+1; j < max(r, nx); j++) {
                        a[j][ny]++;
                    }
                    for (int j = min(c, ny)+1; j < max(c, ny); j++) {
                        a[nx][j]++;
                    }
                }
            }
        } else {
            //移除木樁
            a[r][c] = 0;
        }
        ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += (a[i][j] != 0);
            }
        }
        mx = max(mx, ans);
    }
    cout << mx << "\n" << ans << "\n";
    return 0;
}
