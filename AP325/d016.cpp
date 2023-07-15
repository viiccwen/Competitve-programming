#include <bits/stdc++.h>
using namespace std;

int M, N, ans = 0;
int cnt[38];
map<long long, int> mp;
string s;
long long mask, tmp;

int AlphaToInt(char &c) {
  if (c <= 'Z')
    return c - 'A';
  else
    return c - 'a' + 26;
}

void solve() {
  cin >> M >> N;
  for (int i = 0; i < M; i++) mask |= (1LL << i);

  for (int i = 0; i < N; i++) {
    memset(cnt, 0, sizeof(cnt));
    tmp = 0;
    cin >> s;
    for (int j = 0; j < s.size(); j++) cnt[AlphaToInt(s[j])] = 1;

    for (int j = 0; j < 38; j++)
      if (cnt[j]) tmp |= (1LL << j);

    if (mp.count(tmp ^ mask)) ans += mp[tmp ^ mask];
    mp[tmp]++;
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}