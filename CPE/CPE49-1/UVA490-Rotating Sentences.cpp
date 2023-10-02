#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string temp;
	int i = 0, max_len = 0;

	while (getline(cin, temp)) {
		v.push_back(temp);
		max_len = max(max_len, int(v[i].size()));
		i++;
	}

	for (int j = 0; j < max_len; j++) {
		for (int k = i - 1; k >= 0; k--) {
			if (j >= v[k].size() && k != 0) cout << " ";
			else cout << v[k][j];
		}
		cout << '\n';
	}
}