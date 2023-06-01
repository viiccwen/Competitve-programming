#include <bits/stdc++.h>
using namespace std;

void solution() {
	int n; cin >> n;
	map<string, int> mp;
	string city, a, b;

	for (int i = 0; i < n; i++) {
		cin >> city >> a >> b;
		mp[city]++;
	}

	for (auto i : mp) cout << i.first << ' ' << i.second << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	solution();
}