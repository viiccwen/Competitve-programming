#include <bits/stdc++.h>
#define f first
#define s second
#define lson idx << 1
#define rson (idx << 1) + 1
#define ull unsigned long long
using namespace std;

vector<pair<int, int>> num;

int QL, QR, sums, at;
ull ans;

struct SEG_TREE {
  vector<int> seg;

  void init(int N) { seg.resize(N << 3); }

  void update(int l, int r, int idx = 1) {
    if (l == r) {
      seg[idx] = 1;
      return;
    }

    int mid = (l + r) >> 1;
    if (at <= mid)
      update(l, mid, lson);
    else
      update(mid + 1, r, rson);

    seg[idx] = seg[lson] + seg[rson];
  }

  void query(int l, int r, int idx = 1) {
    if (QL <= l && QR >= r) {
      sums += seg[idx];
      return;
    }

    int mid = (l + r) >> 1;
    if (QL <= mid) query(l, mid, lson);
    if (QR > mid) query(mid + 1, r, rson);
  }
};

SEG_TREE seg;

void solve() {
  int N;
  cin >> N;
  num.resize(N + 1, {-1, -1});
  seg.init(N);
  ans = 0;

  for (int i = 1, tmp; i <= (N << 1); i++) {
    cin >> tmp;
    if (num[tmp].f == -1)
      num[tmp].f = i;
    else
      num[tmp].s = i;
  }

  for (int i = 1; i <= N; i++) {
    QL = num[i].f;
    QR = num[i].s;
    sums = 0;

    seg.query(1, N << 1);
    ans += sums;

    at = num[i].f;
    seg.update(1, N << 1);
    at = num[i].s;
    seg.update(1, N << 1);
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}