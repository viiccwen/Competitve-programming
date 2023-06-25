#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;

void solve() {
  string s, tmp;
  int N;
  unordered_set<string> set;
  cin >> s;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> tmp;
    set.insert(tmp);
  }

  vector<bool> dp(1001, 0);
  for (int i = 0; i < s.size(); i++) {
    tmp = "";
    for (int j = i; j < s.size(); j++) {
      tmp += s[j];
      if (set.count(tmp)) {
        if (!i)
          dp[j] = 1;
        else
          dp[j] = dp[i - 1] | dp[j];
      }
    }
  }

  if (dp[s.size() - 1])
    cout << "yes";
  else
    cout << "no";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
