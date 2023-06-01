#include <bits/stdc++.h>
using namespace std;

void solution() {
	int m; cin >> m;

	vector<int> v(m);
	for (int i = 0; i < m; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	int mid = m / 2, dis = 0;
	for (int i = 0; i < m; i++)
		dis += abs(v[mid] - v[i]);


	cout << dis << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++)
		solution();
}