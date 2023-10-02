#include <bits/stdc++.h>
using namespace std;

void solution(int& a, int& b) {
	int carry = 0, sum = 0;

	while (a > 0 && b > 0) {
		if (a % 10 + b % 10 + carry >= 10) {
			carry = 1;
			sum++;
		}
		else carry = 0;

		a /= 10; b /= 10;
	}

	while (a > 0) {
		if (a % 10 + carry >= 10) {
			carry = 1;
			sum++;
		}
		else carry = 0;

		a /= 10;
	}

	while (b > 0) {
		if (b % 10 + carry >= 10) {
			carry = 1;
			sum++;
		}
		else carry = 0;

		b /= 10;
	}

	if (!sum) cout << "No carry operation.\n";
	else if (sum == 1) cout << "1 carry operation.\n";
	else cout << sum << " carry operations.\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b;

	while (cin >> a >> b && a != 0 && b != 0)
		solution(a, b);
}