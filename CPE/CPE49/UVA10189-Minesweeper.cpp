#include <bits/stdc++.h>
#define SIZE 105
#define f first
#define s second
using namespace std;

char field[SIZE][SIZE];
char result[SIZE][SIZE];
pair<int, int> dir[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                         {0, 1},   {1, -1}, {1, 0},  {1, 1}};
int idx = 1;
bool flag = 0;

void solve() {
  int r, c;
  while (cin >> r >> c && r != 0 && c != 0) {
    if (!flag)
      flag = 1;
    else
      cout << '\n';

    memset(result, '0', sizeof(result));

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> field[i][j];
        if (field[i][j] == '*') result[i][j] = '*';
      }
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (field[i][j] == '*') {
          for (int d = 0; d < 8; d++) {
            int ni = i + dir[d].f, nj = j + dir[d].s;

            if (ni < 0 || nj < 0 || ni > r || nj > c) continue;
            if (result[ni][nj] == '*') continue;
            result[ni][nj]++;
          }
        }
      }
    }

    cout << "Field #" << idx++ << ":\n";
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << result[i][j];
      }
      cout << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}