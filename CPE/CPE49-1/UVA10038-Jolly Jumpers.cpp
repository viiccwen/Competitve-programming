#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		vector<int> v(n);
		vector<int> differ(n - 1);
		set<int> s;
		for (int i = 0, temp; i < n; i++) {
			cin >> v[i];
			if (i) differ[i - 1] = abs(v[i] - v[i - 1]);
		}

		sort(differ.begin(), differ.end());
		bool flag = 1;
		for (int i = 0, start = 1; i < n - 1; i++) {
			if (start++ != differ[i]) {
				flag = 0;
				break;
			}
		}

		if (flag) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
}