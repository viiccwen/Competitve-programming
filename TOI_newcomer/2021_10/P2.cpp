#include <bits/stdc++.h>
using namespace std;

struct Card {
  int number;
  int attack;
  int defense;
  int health;
  int point = 0;
};

Card card[21];

bool cmp1(Card a, Card b) {
  if (a.attack >= b.attack)
    return true;
  else
    return false;
}
bool cmp2(Card a, Card b) {
  if (a.defense >= b.defense)
    return true;
  else
    return false;
}
bool cmp3(Card a, Card b) {
  if (a.health >= b.health)
    return true;
  else
    return false;
}
bool cmp4(Card a, Card b) {
  if (a.point > b.point)
    return true;
  else if (a.point == b.point && a.number < b.number)
    return true;
  else
    return false;
}

void solve() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> card[i].attack >> card[i].defense >> card[i].health;
    card[i].number = i + 1;
  }

  sort(card, card + N, cmp1);
  for (int i = 0, tmp; i < N; i++) {
    if (!i) {
      tmp = card[i].attack;
      card[i].point++;
    } else if (card[i].attack == tmp) {
      card[i].point++;
    } else
      break;
  }

  sort(card, card + N, cmp2);
  for (int i = 0, tmp; i < N; i++) {
    if (!i) {
      tmp = card[i].defense;
      card[i].point++;
    } else if (card[i].defense == tmp) {
      card[i].point++;
    } else
      break;
  }

  sort(card, card + N, cmp3);
  for (int i = 0, tmp; i < N; i++) {
    if (!i) {
      tmp = card[i].health;
      card[i].point++;
    } else if (card[i].health == tmp) {
      card[i].point++;
    } else
      break;
  }

  sort(card, card + N, cmp4);
  cout << card[0].number;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
