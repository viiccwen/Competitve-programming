#include<bits/stdc++.h>
using namespace std;
int BinAdd(int t) {
	int ret = 0;
	while (t >= 2) {
		if (t & 1) ret++;
		t /= 2;
	}
	if (t) ret++;
	return ret;
}

int BcdAdd(int t) {
	int ret = 0;
	string s = to_string(t);

	for (auto c : s) ret += BinAdd(c - '0');

	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, t; cin >> n;
	while (n--) {
		cin >> t;

		cout << BinAdd(t) << ' ' << BcdAdd(t) << '\n';
	}
}