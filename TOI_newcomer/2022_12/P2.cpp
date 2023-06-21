#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(4);
vector<int> mix(4);
int N, ind;

void check() {
  vector<int> ans(4);
  vector<int>::iterator ite;
  int cnt = 1;
  for (int i = 0; i < N; i++) {
    int scale = v[ind][i];
    cnt = 1;
    for (int j = 0; j < 4; j++) {
      if (j == ind) continue;
      ite = find(v[j].begin(), v[j].end(), mix[j] * scale);
      if (ite != v[j].end()) {
        cnt++;
        ans[j] = *ite;
      } else
        break;
    }
    if (cnt == 4) {
      ans[ind] = v[ind][i];
      break;
    }
  }

  if (cnt != 4)
    cout << "-1";
  else {
    for (int i = 0; i < 4; i++) cout << ans[i] << ' ';
  }
}

void solve() {
  for (int i = 0; i < 4; i++) cin >> mix[i];
  for (int i = 0; i < 4; i++) {
    if (mix[i] == 1) {
      ind = i;
      break;
    }
  }

  cin >> N;
  for (int i = 0; i < 4; i++) v[i].resize(N);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < N; j++) cin >> v[i][j];
  }

  check();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}