#include <bits/stdc++.h>
using namespace std;

struct Dice {
  int top;
  int north;
  int south;
  int west;
  int east;
  int down;
};

Dice dice;

void init() {
  dice.top = 1;
  dice.down = 6;
  dice.north = 2;
  dice.south = 5;
  dice.west = 3;
  dice.east = 4;
}

void left() {
  int tmp = dice.top;
  dice.top = dice.east;
  dice.east = dice.down;
  dice.down = dice.west;
  dice.west = tmp;
}
void right() {
  int tmp = dice.top;
  dice.top = dice.west;
  dice.west = dice.down;
  dice.down = dice.east;
  dice.east = tmp;
}
void toward() {
  int tmp = dice.top;
  dice.top = dice.south;
  dice.south = dice.down;
  dice.down = dice.north;
  dice.north = tmp;
}
void backward() {
  int tmp = dice.top;
  dice.top = dice.north;
  dice.north = dice.down;
  dice.down = dice.south;
  dice.south = tmp;
}

void solve() {
  string func;
  cin >> func;
  if (func == "north")
    toward();
  else if (func == "south")
    backward();
  else if (func == "east")
    right();
  else if (func == "west")
    left();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  while (cin >> N && N != 0) {
    init();
    while (N--) solve();
    cout << dice.top << '\n';
  }
}