#include <bits/stdc++.h>
using namespace std;

set<char> st;
set<char> hit;
string ans, guess;

int hangman() {
  cin >> ans >> guess;
  st.clear();
  hit.clear();

  for (auto i : ans) st.insert(i);

  int Round = 0;
  for (auto i : guess) {
    if (Round == 7 || st.size() == hit.size()) break;

    if (st.count(i))
      hit.insert(i);
    else
      Round++;
  }

  if (Round == 7)
    return 0;
  else if (st.size() == hit.size())
    return 1;
  else
    return 2;

  return 0;
}

void solve() {
  int N;

  while (cin >> N && N != -1) {
    int a = hangman();
    cout << "Round " << N << '\n';
    if (a == 0)
      cout << "You lose.";
    else if (a == 1)
      cout << "You win.";
    else
      cout << "You chickened out.";
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}

/*
1
cheese
abcdefg
2
cheese
abcdefgij
-1
*/