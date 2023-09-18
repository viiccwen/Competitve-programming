#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1,
                                      vector<vector<int>>& items2) {
  vector<vector<int>> v;
  sort(items1.begin(), items1.end());
  sort(items2.begin(), items2.end());
  int ite1 = 0, ite2 = 0;

  while (ite1 < items1.size() || ite2 < items2.size()) {
    if (ite1 == items1.size())
      v.push_back(items2[ite2++]);
    else if (ite2 == items2.size())
      v.push_back(items1[ite1++]);
    else {
      if (items1[ite1][0] < items2[ite2][0])
        v.push_back(items1[ite1++]);
      else if (items1[ite1][0] > items2[ite2][0])
        v.push_back(items2[ite2++]);
      else {
        v.push_back({items1[ite1][0], items1[ite1][1] + items2[ite2][1]});
        ite1++, ite2++;
      }
    }
  }

  return v;
}

void solve() {
  vector<vector<int>> items1 = {{{5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}}},
                      items2 = {{7, 1}, {6, 2}, {5, 3}, {4, 4}};
  vector<vector<int>> k = mergeSimilarItems(items1, items2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}