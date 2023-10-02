#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b, ans = 0;
	while (cin >> a >> b && a && b) {
		ans ^= ans;

		for (int i = 1; i <= sqrt(b); i++)
			if (i * i >= a && i * i <= b) ans++;

		cout << ans << '\n';
	}
}