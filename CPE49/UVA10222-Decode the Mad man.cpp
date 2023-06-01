#include <bits/stdc++.h>
using namespace std;
// 注意反斜線要反反斜線
string table = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

void solution() {
	string s; //cout << s << '\n';

	while (getline(cin, s)) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') cout << ' ';
			else cout << table[table.find(tolower(s[i])) - 2];
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solution();
}