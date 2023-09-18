#include <bits/stdc++.h>
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

vector<int> nums1 = {1, 3, 3, 2};
vector<int> nums2 = {2, 1, 3, 4};
int k = 3;

struct cmp {
  bool operator()(pii &a, pii &b) {
    if (a.S == b.S) return a.F < b.F;
    return a.S < b.S;
  }
};

void solve() {
  priority_queue<pii, vector<pii>, cmp> pq;

  for (int i = 0; i < nums1.size(); i++) {
    pq.push({nums1[i], nums2[i]});
  }
  int num = 0, mul = 1e6;
  for (int i = 0; i < k; i++) {
    cout << pq.top().F << ' ' << pq.top().S << '\n';
    // num += pq.top().F;
    // mul = min(mul, pq.top().S);
    pq.pop();
  }

  cout << num * mul;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}