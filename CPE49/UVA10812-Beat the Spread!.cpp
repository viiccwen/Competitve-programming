#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int a, b;
	while (n--) {
		cin >> a >> b;

		if (a < b) cout << "impossible\n";

		else if ((a + b) % 2 || (a - b) % 2) cout << "impossible\n";

		else cout << (a + b) / 2 << ' ' << (a - b) / 2 << '\n';
	}
}