#include <bits/stdc++.h>
#define ll long long
#include <unordered_set>
using namespace std;

unordered_set<char> Set = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

void solve() {
  ll N;
  cin >> N;
  cin.ignore();
  for (ll i = 1; i <= N; i++) {
    string s;
    getline(cin, s);
    char c = s[s.size() - 1];
    if (c == 'y')
      cout << "Case #" << i << ": " << s << " is ruled by nobody.\n";
    else if (Set.count(c))
      cout << "Case #" << i << ": " << s << " is ruled by Alice.\n";
    else
      cout << "Case #" << i << ": " << s << " is ruled by Bob.\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
