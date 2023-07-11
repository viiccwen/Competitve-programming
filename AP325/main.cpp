#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;

ll rec();

ll h() {
  ll x = rec(), y = rec(), z = rec();
  return 3 * x - 2 * y + z;
}

ll g() {
  ll x = rec(), y = rec();
  return 2 * x + y - 7;
}

ll f() {
  ll x = rec();
  return 2 * x - 3;
}

ll rec() {
  cin >> s;
  if (s == "f")
    return f();
  else if (s == "g")
    return g();
  else if (s == "h")
    return h();
  else
    return stoi(s);
}

void solve() { cout << rec() << '\n'; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}