#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;

void solve() {
  int x;
  cin >> x;
  int Short = x, Long = 2 * x, high = x, width;

  width = Short + (Short / 2) + (Short - 1) + (Long - 1);
  if (x % 2 == 0) width--;
  // if(x % 2) width = Short + (Short / 2) + (Short - 1) + (Long - 1);
  // else width = Short + (Short / 2 - 1) + (Short - 1) + (Long - 1);

  v.resize(high);
  for (int i = 0; i < high; i++) v[i].resize(width, ' ');

  int short_high_scale = x / 2;
  int short_end_scale = x - 1;
  int long_start_scale = Short + (Short / 2) + (Short - 1) - 1;

  short_high_scale = x / 2;
  if (x % 2 == 0) {
    long_start_scale--;
  }

  int right_ob = long_start_scale - 1;
  int left_ob = short_end_scale + 1;

  for (int i = 0; i < high; i++) {
    if (i > 1) right_ob--;
    if (i > x / 2) left_ob++;

    for (int j = 0; j < width; j++) {
      if (i == 0 && j >= long_start_scale) {
        v[i][j] = '*';
        continue;
      }

      if (i > 0 && j == right_ob) v[i][j] = '*';
      if (i > short_high_scale && j == left_ob - 1) v[i][j] = '*';

      if (i == short_high_scale && j < Short) v[i][j] = '*';
    }
  }

  for (int i = 0; i < high; i++) {
    for (int j = 0; j < width; j++) {
      cout << v[i][j];
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}

/*
if: cin >> x
short x
long 2*x
high x
odd_width = short + (short / 2) + (short - 1) + (long - 1)
even_width = short + (short / 2 - 1) + (short - 1) + (long - 1)
even_width = odd_width
*/