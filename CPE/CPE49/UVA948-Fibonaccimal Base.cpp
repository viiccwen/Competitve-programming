#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    int t;
    cin >> t;
    // cout << t << '\n';
    if (t == 1) {
      cout << "1 = 1 (fib)\n";
      continue;
    } else if (t == 2) {
      cout << "2 = 10 (fib)\n";
      continue;
    }

    vector<int> fib(10000);
    fib[0] = 1;
    fib[1] = 2;
    int maxup = 0;
    for (int i = 2; i < 10000; i++) {
      fib[i] = fib[i - 2] + fib[i - 1];

      if (t < fib[i]) {
        maxup = i - 1;
        break;
      } else if (t == fib[i]) {
        maxup = i;
        break;
      }
    }
    string fibs = "";
    int cal = t;
    for (int i = maxup; i >= 0; i--) {
      if (cal >= fib[i]) {
        fibs += "1";
        cal -= fib[i];
      } else
        fibs += "0";
    }

    cout << t << " = " << fibs << " (fib)\n";
  }
}