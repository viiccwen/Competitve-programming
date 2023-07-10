#include <bits/stdc++.h>
using namespace std;

int finger[11];
bool last_move[11];
//                                  0  1  2  3  4  5  6  7  8  9  10
map<char, vector<int>> mp = {{'a', {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
                             {'b', {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
                             {'c', {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1}},
                             {'d', {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
                             {'e', {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
                             {'f', {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
                             {'g', {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
                             {'A', {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
                             {'B', {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
                             {'C', {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
                             {'D', {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
                             {'E', {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
                             {'F', {0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
                             {'G', {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}}};

void move(char c) {
  int k = 0;
  for (auto i : mp[c]) {
    if (!last_move[k] && i) {
      finger[k]++;
      last_move[k] = 1;
    } else if (!i)
      last_move[k] = 0;

    k++;
  }
}

void solve() {
  string s;
  getline(cin, s);
  int len = s.size();

  for (auto c : s) {
    move(c);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  cin.ignore();
  while (N--) {
    memset(finger, 0, sizeof(finger));
    memset(last_move, 0, sizeof(last_move));
    solve();
    for (int i = 1; i <= 9; i++) cout << finger[i] << ' ';
    cout << finger[10] << '\n';
  }
}