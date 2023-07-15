#include <bits/stdc++.h>
using namespace std;

int M, N, ans = 0;
string s;
bitset<30> mask;
unordered_map<long long, int> mp;

void solve() {
  cin >> M >> N;
  mask = (1LL << M) - 1;

  for (int i = 0; i < N; i++) {
    cin >> s;
    bitset<30> bs;
    for (auto c : s) bs[c - 'A'] = 1;
    long long tmp = bs.to_ullong();
    bs ^= mask;
    if (mp.find(bs.to_ullong()) != mp.end()) ans += mp[bs.to_ullong()];
    mp[tmp]++;
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}