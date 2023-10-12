#include <bits/stdc++.h>
using namespace std;

void solve() {
  double point[2][4];
  while (cin >> point[0][0] >> point[1][0] >> point[0][1] >> point[1][1] >>
         point[0][2] >> point[1][2] >> point[0][3] >> point[1][3]) {
    double dupVal[2];  // Xval Yval
    double dupIdx[2];  // Idx
    double demand[2] = {0, 0};

    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        if (point[0][i] == point[0][j] && point[1][i] == point[1][j]) {
          dupVal[0] = point[0][i];
          dupVal[1] = point[1][i];
          dupIdx[0] = i;
          dupIdx[1] = j;
          break;
        }
      }
    }

    for (int i = 0; i < 4; i++) {
      if (i != dupIdx[0] && i != dupIdx[1]) {
        demand[0] += point[0][i];
        demand[1] += point[1][i];
      }
    }

    printf("%.3f %.3f\n", demand[0] - dupVal[0], demand[1] - dupVal[1]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}