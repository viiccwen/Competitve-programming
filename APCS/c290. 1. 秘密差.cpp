#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int odd = 0, even = 0;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0)
			odd += s[i] - '0';
		else
			even += s[i] - '0';
	}
	cout << abs(odd - even);
}
