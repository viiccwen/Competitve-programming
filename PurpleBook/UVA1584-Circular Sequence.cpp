#include <bits/stdc++.h>
using namespace std;

vector<string> gene;

void solve() {
  string s;
  cin >> s;
  int len = s.size();
  gene.assign(len, "");
  for (int i = 0; i < len; i++) {
    string tmp = "";
    for (int j = i; j < len; j++) tmp += s[j];
    for (int k = 0; k < i; k++) tmp += s[k];
    gene[i] = tmp;
  }
  sort(gene.begin(), gene.end());
  cout << gene[0] << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  while (N--) solve();
}
