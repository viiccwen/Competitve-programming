#include <bits/stdc++.h>
using namespace std;

vector<string> puzzle(5);
string func;
string ans;
int Round = 0;
int overflag = 0;
pair<int, int> cur;

bool check() {}

void move(char fuc) {}

pair<int, int> find_pos() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (puzzle[i][j] == ' ') {
        return {i, j};
      }
    }
  }
}

void solve() {
  string s;
  while (getline(cin, s) && s != "Z") {
    puzzle[0] = s;
    for (int i = 1; i < 5; i++) {
      getline(cin, s);
      puzzle[i] = s;
    }

    ans = "Puzzle #" + to_string(++Round) + ":\n";

    cur = find_pos();

    while (cin >> func) {
      if (func[func.size() - 1] == '0') overflag = 1;

      for (int i = 0; i < func.size(); i++) {
        if (func[i] == '0') continue;

        move(func[i]);
      }

      if (overflag) break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
