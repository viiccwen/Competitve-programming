#include <bits/stdc++.h>
using namespace std;

string s;
map<string, int> mp;
int num = 0;

void solve() {
  int N;
  cin >> N;
  cin.ignore();
  getline(cin, s);
  while (N--) {
    mp.clear();

    num = 0;
    while (getline(cin, s) && s != "") {
      num++;
      mp[s]++;
    }
    for (auto k : mp) {
      float pro = float(100) / float(num) * float(k.second);
      cout << k.first << ' ' << fixed << setprecision(4) << pro << '\n';
    }
    if (N) cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}