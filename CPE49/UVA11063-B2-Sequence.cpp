#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, no = 1;
	while (cin >> n) {
		vector<int> v(n);
		unordered_set<int> s;
		bool flag = 1;

		for (auto& i : v) cin >> i;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (!s.count(v[i] + v[j]))
					s.insert(v[i] + v[j]);
				else {
					flag = 0; break;
				}
			}
		}

		cout << "Case #" << no++ << ": ";
		if (flag) cout << "It is a B2-Sequence.\n\n";
		else cout << "It is not a B2-Sequence.\n\n";
	}
}