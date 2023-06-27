#include <bits/stdc++.h>
#define SIZE 200001
#define ll long long
using namespace std;

vector<int> v;
vector<int> t;
int n, m, a, b, w;
ll ans;

struct BIT {
  int sz;
  vector<int> dat;

  void init(int N) {
    sz = N;
    dat.assign(sz + 2, 0);
    return;
  }

  void update(int i, int x) {
    for (; i <= sz; i += i & (-i)) dat[i] += x;
    return;
  }

  int sum(int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i)) sum += dat[i];
    return sum;
  }
};

BIT bit;

bool cmp(int a, int b) { return a > b; }

void solve() {
  cin >> n >> m;
  bit.init(n);

  while (m--) {
    cin >> a >> b >> w;
    bit.update(a, w);
    bit.update(b + 1, -w);
  }

  v.assign(n, 0);
  t.assign(n, 0);

  for (int i = 0; i < n; i++) v[i] = bit.sum(i + 1);
  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < n; i++) cin >> t[i];
  sort(t.begin(), t.end());

  ans = 0;
  for (int i = 0; i < n; i++) ans += v[i] * t[i];
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}