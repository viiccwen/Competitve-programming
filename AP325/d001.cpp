#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;

ll rec();

ll g() {
  ll x = rec();
  ll y = rec();
  return x + 2 * y - 3;
}

ll f() {
  ll x = rec();
  return 2 * x - 1;
}

ll rec() {
  cin >> s;
  if (s == "f")
    return f();
  else if (s == "g")
    return g();
  else
    return stoi(s);
}

void solve() { cout << rec() << '\n'; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}