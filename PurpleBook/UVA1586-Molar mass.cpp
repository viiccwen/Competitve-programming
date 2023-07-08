#include <bits/stdc++.h>
using namespace std;

string s;
int len;
unordered_map<char, float> mp = {
    {'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01}};

int digit(int idx) {
  int sum = 0;
  vector<int> digit;
  while (idx < len) {
    if (isdigit(s[idx])) {
      digit.push_back(s[idx] - '0');
      idx++;
    } else
      break;
  }
  if (!digit.empty()) {
    int k = 1;
    for (int i = digit.size() - 1; i >= 0; i--) {
      sum += digit[i] * k;
      k *= 10;
    }
  }

  if (sum == 0)
    return 1;
  else
    return sum;
}

void solve() {
  cin >> s;
  len = s.size();
  float ans = 0;

  for (int i = 0; i < len; i++) {
    ans += mp[s[i]] * digit(i + 1);
  }

  cout << fixed << setprecision(3) << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  while (N--) solve();
}
