#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ull s, d;
	while (cin >> s >> d) {
		ull days = 1;

		while (days <= d) days += s++;

		cout << s - 1 << '\n';
	}
}