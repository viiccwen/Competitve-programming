#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll x, tmp;
	stringstream ss;
	string s;
	while (cin >> x) {
		vector<ll> v;
		getline(cin, s); getline(cin, s); ss << s;

		ll tmp, ans = 0;
		while (ss >> tmp) v.push_back(tmp);

		ll len = v.size() - 2;
		ll xp = 1;
		for (ll i = len; i >= 0; i--, xp++)
			ans += pow(x, len - i) * v[i] * xp;

		cout << ans << '\n';
		ss.str(""); ss.clear();
	}
}