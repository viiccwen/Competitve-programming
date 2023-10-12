#include <bits/stdc++.h>
#define PI 3.14159265358
using namespace std;

void solve() {
  double earth_r = 6440.0;
  double s, angle;
  double arcDist, chordDist;
  string unit;

  while (cin >> s >> angle >> unit) {
    // 1 degree = 60 arc min
    if (unit == "min") angle /= 60;

    while (angle > 360) angle -= 360;

    if (angle > 180) angle = 360 - angle;

    arcDist = (earth_r + s) * (angle * (PI / 180));
    chordDist = 2 * (earth_r + s) * sin((angle * (PI / 180)) / 2);

    printf("%.6f %.6f\n", arcDist, chordDist);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}