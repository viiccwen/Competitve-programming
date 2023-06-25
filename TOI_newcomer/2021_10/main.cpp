#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  string s;
  vector<int> ans;
  cin >> N >> s;

  for (int i = 0; i < s.size(); i += N) {
    int sum = 0;
    for (int j = i; j < i + N; j++) {
      if (j < s.size()) sum += s[j] - '0';
    }
    ans.push_back(sum);
    cout << sum << '\n';
  }

  sort(ans.begin(), ans.end());
  bool flag = 0;

  for (int i = 0; i < ans.size(); i++) {
    int target = ans[i];

    for (int j = i + 1; j < ans.size(); j++) {
      if (ans[j] == target) {
        flag = 1;
        break;
      } else {
        i = j;
        break;
      }
    }

    if (flag) break;
  }

  if (flag)
    cout << "Yes";
  else
    cout << "No";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
