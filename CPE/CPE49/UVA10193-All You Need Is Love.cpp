#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL STOI(string str) {
  LL num = 0;
  for (int i = str.size() - 1, tmp = 1; i >= 0; i--) {
    num += tmp * (str[i] - '0');
    tmp *= 2;
  }

  return num;
}

LL gcd(LL a, LL b) {
  LL tmp;
  while (b > 0) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

void solve() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    string str_a, str_b;
    cin >> str_a >> str_b;

    LL num_a = STOI(str_a);
    LL num_b = STOI(str_b);

    if (num_a < num_b) swap(num_a, num_b);

    num_a = gcd(num_a, num_b);

    if (num_a == 1)
      cout << "Pair #" << i << ": Love is not all you need!\n";
    else
      cout << "Pair #" << i << ": All you need is love!\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}