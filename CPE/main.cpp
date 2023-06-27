#include <bits/stdc++.h>
using namespace std;

void check(vector<int> &jolly) {
  for (int i = 0; i < jolly.size(); i++) {
    if (jolly[i] != i + 1) {
      cout << "Not jolly\n";
      return;
    }
  }
  cout << "Jolly\n";
}

void solve() {
  int N;

  while (cin >> N) {
    vector<int> v, jolly;
    for (int i = 0, tmp; i < N; i++) {
      cin >> tmp;
      v.push_back(tmp);
    }
    for (int i = 0; i < v.size() - 1; i++)
      jolly.push_back(abs(v[i + 1] - v[i]));

    sort(jolly.begin(), jolly.end());
    check(jolly);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}