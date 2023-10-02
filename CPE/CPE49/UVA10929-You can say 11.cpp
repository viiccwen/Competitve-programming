#include <bits/stdc++.h>
using namespace std;

void solution(string& s) {
	int len = s.size();
	int odd = 0, even = 0;

	for (int i = 0; i < len; i++) {
		if ((i + 1) % 2 == 0) even += s[i] - '0';
		else odd += s[i] - '0';
	}

	if (even == odd || abs(even - odd) % 11 == 0) cout << s << " is a multiple of 11.\n";
	else cout << s << " is not a multiple of 11.\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;

	while (cin >> s && s != "0")
		solution(s);
}