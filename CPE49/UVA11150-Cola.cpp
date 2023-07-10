#include <bits/stdc++.h>
using namespace std;

int N;

void solve() {
  while (cin >> N) cout << N * 3 / 2 << '\n';
  /*
  3 empty cola exchange 1 new cola
  every exchange -> substract 2 cola bottle and get 1 new cola
  so ans = (N + exchange times)
  exchange:
  time  result
  1       8
  2       3
  3       1
  total   12

  3瓶空可樂罐換一瓶可樂"代表每換一次瓶子的數量減少2，而實際喝的可樂數增加1，所以最終答案等於N+換的次數。
  原本數量N，換一次後剩下N-2，兩次N-2*2，以此類推，可以看出能換N/2次。所以答案是N+N/2=N*3/2
  */
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}