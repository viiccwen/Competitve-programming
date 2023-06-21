#include <bits/stdc++.h>
using namespace std;

struct Wave {
  char dir;
  double time;
};

Wave wave[201];
map<char, int> val = {{'N', 1}, {'E', 2}, {'S', 3}, {'W', 4}};

bool cmp(Wave a, Wave b) {
  if (a.time < b.time)
    return true;
  else if (a.time == b.time) {
    if (val[a.dir] >= val[b.dir])
      return true;
    else
      return false;
  } else
    return false;
}

void solve() {
  int p;
  cin >> p;

  for (int i = 0; i < p; i++) {
    char chr;
    double d, v;
    cin >> chr >> d >> v;
    wave[i].dir = chr;
    wave[i].time = d / v;
  }

  sort(wave, wave + p, cmp);

  for (int i = 0; i < p; i++) cout << wave[i].dir;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
