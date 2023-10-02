#include <bits/stdc++.h>
using namespace std;

int Reverse(int num) {
  string s = to_string(num);
  reverse(s.begin(), s.end());
  return stoi(s);
}

bool prime(int num) {
  if (num == 1) return 0;

  for (int i = 2; i <= sqrt(double(num)); i++) {
    if (num % i == 0) return 0;
  }

  return 1;
}

void solve() {
  int N;
  while (cin >> N) {
    int revN = Reverse(N);
    bool pf = prime(N);
    bool revpf = prime(revN);

    if (!pf)
      cout << N << " is not prime.\n";
    else if (pf && revpf && revN != N)
      cout << N << " is emirp.\n";
    else if (pf)
      cout << N << " is prime.\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}