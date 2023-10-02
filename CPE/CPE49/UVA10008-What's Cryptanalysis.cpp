#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

void solution() {
	int n; cin >> n;
	map<char, int> mp;
	string s; getline(cin, s);

	for (int i = 0; i < n; i++) {

		getline(cin, s);
		for (int j = 0; j < s.size(); j++) {

			if (isalpha(s[j])) {
				if (islower(s[j])) mp[toupper(s[j])]++;
				else mp[s[j]]++;
			}
		}
	}

	vector<pair<char, int>> v;
	for (auto c : mp) v.push_back({ c.first, c.second });

	sort(v.begin(), v.end(), cmp);

	for (auto c : v) cout << c.first << ' ' << c.second << '\n';

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	solution();
}