#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;

struct Pos {
  int x;
  int y;
  char d;
};

unordered_map<char, pii> dir = {
    {'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}};

Pos pos;

int r, c;
string s;
bool lost;
vector<pii> scent;

void turnR() {
  if (pos.d == 'E')
    pos.d = 'S';
  else if (pos.d == 'S')
    pos.d = 'W';
  else if (pos.d == 'W')
    pos.d = 'N';
  else if (pos.d == 'N')
    pos.d = 'E';
}

void turnL() {
  if (pos.d == 'E')
    pos.d = 'N';
  else if (pos.d == 'N')
    pos.d = 'W';
  else if (pos.d == 'W')
    pos.d = 'S';
  else if (pos.d == 'S')
    pos.d = 'E';
}

void move() {
  int nx = pos.x + dir[pos.d].f, ny = pos.y + dir[pos.d].s;
  if (nx < 0 || nx > r || ny < 0 || ny > c) {
    bool flag = 1;
    for (auto p : scent) {
      if (pos.x == p.f && pos.y == p.s) {
        flag = 0;
        break;
      }
    }

    if (flag) {
      lost = 1;
      scent.push_back({pos.x, pos.y});
    }
  } else {
    pos.x = nx, pos.y = ny;
  }
}

void solve() {
  cin >> r >> c;
  while (cin >> pos.x >> pos.y >> pos.d) {
    cin >> s;
    lost = 0;
    for (auto i : s) {
      if (lost)
        break;
      else if (i == 'R')
        turnR();
      else if (i == 'L')
        turnL();
      else {
        move();
      }
    }

    if (lost)
      cout << pos.x << ' ' << pos.y << ' ' << pos.d << ' ' << "LOST\n";
    else
      cout << pos.x << ' ' << pos.y << ' ' << pos.d << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}