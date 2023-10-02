#include <bits/stdc++.h>
using namespace std;

int G;
int N;

int GCD(int m, int n) {
  int r = 0;
  while (n != 0) {
    r = m % n;
    m = n;
    n = r;
  }

  return m;
}

void solve() {
  while (cin >> N && N != 0) {
    G = 0;

    for (int i = 1; i < N; i++) {
      for (int j = i + 1; j <= N; j++) G += GCD(i, j);
    }

    cout << G << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}