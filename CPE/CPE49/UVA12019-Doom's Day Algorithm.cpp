#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int m, d, days = 0;
	int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string day[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	while (n--) {
		cin >> m >> d;

		days ^= days;
		for (int i = 0; i < m; i++) days += month[i];
		days = (days + d + 4) % 7;

		cout << day[days] << '\n';
	}
}