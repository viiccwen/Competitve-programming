#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

unordered_map<int, int> mp;
vector<pair<int, int>> domino(1001);
vector<int> visited(1001, 0);

void push(int& cur) {
  if (mp[cur] == -1) return;

  cout << mp[cur] << ' ';
  push(mp[cur]);
}

void solve() {
  int N;
  cin >> N;
  for (int i = 0, a, b; i < N; i++) {
    cin >> a >> b;
    domino[i] = {a, b};
    mp[a] = b;
  }

  for (int i = 0; i < N; i++) {
    visited[domino[i].f]++;
    if (domino[i].s != -1) visited[domino[i].s]--;
  }

  for (int i = 0; i < 1001; i++) {
    if (visited[i]) {
      cout << i << ' ';
      push(i);
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
