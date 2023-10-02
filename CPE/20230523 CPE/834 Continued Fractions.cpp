#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int a, b;

void solve() {
  while (cin >> a >> b) {
    ans.clear();
    while (b > 1) {
      int m = a / b, n = a % b;
      ans.push_back(m);
      a = b, b = n;
    }
    ans.push_back(a);

    cout << '[' << ans[0] << ';';
    for (int i = 0; i < ans[0]; i++) {
      cout << ans[i + 1] << ',';
    }

    cout << ans[ans[0] + 1] << "]\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}