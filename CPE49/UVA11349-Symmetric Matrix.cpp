#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, n, no = 1; cin >> t;
	char c;
	while (t--) {
		cin >> c >> c >> n;
		vector<vector<int>> v(n, vector<int>(n));
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];

		bool flag = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] != v[n - i - 1][n - j - 1] || v[i][j] < 0) {
					flag = 0;
					break;
				}
			}
		}

		cout << "Test #" << no++ << ": ";
		if (flag) cout << "Symmetric.\n";
		else cout << "Non-symmetric.\n";
	}
}