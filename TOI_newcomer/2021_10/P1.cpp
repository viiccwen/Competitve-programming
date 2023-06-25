#include <bits/stdc++.h>
using namespace std;

int m1, d1, m2, d2;
map<int, int> month = {{1, 31}, {2, 28}, {3, 31}, {4, 30},  {5, 31},  {6, 30},
                       {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

int total() {
  int sum = 0;

  if (m1 == m2)
    sum = d2 - d1 + 1;
  else {
    for (int i = m1; i <= m2; i++) {
      if (i == m1)
        sum += month[i] - d1 + 1;
      else if (i == m2)
        sum += d2;
      else
        sum += month[i];
    }
  }

  return sum;
}

void solve() {
  cin >> m1 >> d1 >> m2 >> d2;
  int days = total();
  days -= (days / 10);
  cout << days * 100;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
