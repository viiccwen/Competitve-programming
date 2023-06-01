#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	long n;
	while (cin >> n && n) {
		int ret = 0;
		string bin = "", tmp = "";
		while (n >= 2) {
			if (n & 1) { tmp += "1"; ret++; }
			else tmp += "0";

			n /= 2;
		}
		if (n) { tmp += "1"; ret++; }
		else tmp += "0";

		int index = tmp.size() - 1;
		for (int i = index; i >= 0; i--)
			if (tmp[i] == '1') { index = i; break; }

		for (int i = index; i >= 0; i--) bin += tmp[i];

		cout << "The parity of " << bin << " is " << ret << " (mod 2).\n";
	}

}