#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int no = 1, a, b;
	ull ans = 0;
	while (n--) {
		ans ^= ans;
		cin >> a >> b;
		if (!(a & 1)) a++;
		for (int i = a; i <= b; i += 2) ans += i;

		cout << "Case " << no++ << ": " << ans << '\n';
	}
}