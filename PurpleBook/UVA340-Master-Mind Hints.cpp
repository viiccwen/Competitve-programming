#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<bool> ans_f;
vector<int> guess;
vector<bool> guess_f;

string str = "";
int Round = 1;
int A, B;

bool check(vector<int> &guess) {
  for (auto i : guess)
    if (i != 0) return 1;
  return 0;
}

void game(vector<int> &ans, vector<int> &guess) {
  A = 0, B = 0;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == guess[i]) {
      A++;
      ans_f[i] = 1;
      guess_f[i] = 1;
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans.size(); j++) {
      if (i == j) continue;

      if (ans[i] == guess[j] && !ans_f[i] && !guess_f[j]) {
        B++;
        ans_f[i] = 1;
        guess_f[j] = 1;
      }
    }
  }
}

void solve() {
  int N;
  while (cin >> N && N != 0) {
    ans.assign(N, 0);
    guess.assign(N, 0);

    str = "Game " + to_string(Round++) + ":\n";

    for (auto &i : ans) cin >> i;

    while (1) {
      A = B = 0;
      ans_f.assign(N, 0);
      guess_f.assign(N, 0);

      for (auto &i : guess) cin >> i;

      if (check(guess)) {
        game(ans, guess);
        str += "    (" + to_string(A) + "," + to_string(B) + ")\n";
      } else {
        cout << str;
        break;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
