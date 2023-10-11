#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  while (getline(cin, s)) {
    int sum = 0, maximum = 1, tmp;

    for (auto chr : s) {
      if (isdigit(chr))
        tmp = chr - '0';
      else if (isupper(chr))
        tmp = chr - 'A' + 10;
      else if (islower(chr))
        tmp = chr - 'a' + 36;
      else
        continue;

      maximum = max(maximum, tmp);
      sum += tmp;
    }

    int k = maximum;
    while (k < 62) {
      if (sum % k == 0) {
        cout << k + 1 << '\n';
        break;
      }
      k++;
    }

    if (k == 62) cout << "such number is impossible!\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}