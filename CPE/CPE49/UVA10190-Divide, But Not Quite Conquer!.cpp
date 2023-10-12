#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> vec;
    bool flag = true;

    if (m == 1) {
      cout << "Boring!" << '\n';
      continue;
    }

    while (n > 1) {
      if (n % m) {
        flag = false;
        break;
      } else {
        vec.push_back(n);
        n /= m;
      }
    }

    if (!flag)
      cout << "Boring!" << '\n';
    else {
      for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
      cout << "1\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}