#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> mat;
int n;

bool checked() {
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n; j++)
      if (mat[i][j] != mat[n - i - 1][n - j - 1]) return false;
  }

  return true;
}

void solve() {
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    char tmp1, tmp2;
    cin >> tmp1 >> tmp2 >> n;
    mat.assign(n, vector<long long int>(n, 0));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cin >> mat[i][j];

    if (checked())
      cout << "Test #" << i << ": Symmetric.\n";
    else
      cout << "Test #" << i << ": Non-symmetric.\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
/*
1
N = 4
5 2 3 4
5 3 3 4
4 3 2 5
4 3 2 5

if(mat[i][j] == mat[r-i-1][c-j-1])


2
N = 3
5 1 3
2 0 2
3 1 5
N = 3
5 1 3
2 0 2
0 1 5
*/