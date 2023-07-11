#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define f first
#define s second
int N;
vector<pii> p;
set<ll> st;
ll L, ans = 0;

bool cmp(pii a, pii b) {
  if (a.s < b.s)
    return true;
  else
    return false;
}

void solve() {
  cin >> N >> L;
  p.resize(N);
  for (int i = 0, idx, tmp; i < N; i++) cin >> p[i].f >> p[i].s;
  sort(p.begin(), p.end(), cmp);
  st.insert(0), st.insert(L);
  for (int i = 0; i < N; i++) {
    st.insert(p[i].f);
    auto pre = st.find(p[i].f), nxt = pre;
    pre--, nxt++;
    ans += *nxt - *pre;
  }
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}