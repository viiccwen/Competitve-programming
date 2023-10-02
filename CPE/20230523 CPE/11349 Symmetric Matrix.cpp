#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> mat;
int n;

bool check() {
  bool flag = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
      if (mat[i][j] < 0) flag = false;
    }
  }

  if (!flag) return false;

  for (int i = 0; i < n / 2 + 1; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] != mat[n - i - 1][n - j - 1]) return false;
    }
  }

  return true;
}

void solve() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    char tmp;
    cin >> tmp >> tmp >> n;

    mat.assign(n, vector<ll>(n, 0));

    if (check())
      cout << "Test #" << i << ": Symmetric." << '\n';
    else
      cout << "Test #" << i << ": Non-symmetric." << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}