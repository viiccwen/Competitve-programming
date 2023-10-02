#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull ans = 0;

void solution() {
	string s;
	while (cin >> s && s != "0") {

		while (s.size() > 1) {
			for (int i = 0; i < s.size(); i++)	ans += s[i] - '0';

			s = to_string(ans); ans ^= ans;
		}

		if (s.size() == 1 && ans == 0) cout << s << '\n';
		else cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	solution();
}