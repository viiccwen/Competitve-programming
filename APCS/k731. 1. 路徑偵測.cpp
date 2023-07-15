#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define x first
#define y second

int N;
int l = 0, r = 0, ret = 0;
int dir = 0;  // 0 右 1 左  2 下  3 上
pii pos = {0, 0};

int x, y;

void move() {
  if (dir == 0) {
    if (pos.y > y) {
      r++, dir = 2;
    } else if (pos.y < y) {
      l++, dir = 3;
    } else if (pos.x > x) {
      ret++, dir = 1;
    } else if (pos.x < x) {
    }
  } else if (dir == 1) {
    if (pos.y > y) {
      l++, dir = 2;
    } else if (pos.y < y) {
      r++, dir = 3;
    } else if (pos.x > x) {
    } else if (pos.x < x) {
      ret++, dir = 0;
    }
  } else if (dir == 2) {
    if (pos.y > y) {
    } else if (pos.y < y) {
      ret++, dir = 3;
    } else if (pos.x > x) {
      r++, dir = 1;
    } else if (pos.x < x) {
      l++, dir = 0;
    }
  } else if (dir == 3) {
    if (pos.y > y) {
      ret++, dir = 2;
    } else if (pos.y < y) {
    } else if (pos.x > x) {
      l++, dir = 1;
    } else if (pos.x < x) {
      r++, dir = 0;
    }
  }
}

void solve() {
  cin >> N;
  while (N--) {
    cin >> x >> y;
    move();
    pos.x = x, pos.y = y;
  }

  cout << l << ' ' << r << ' ' << ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}