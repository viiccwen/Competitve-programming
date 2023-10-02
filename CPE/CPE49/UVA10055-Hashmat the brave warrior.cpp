#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solution(ll& a, ll& b) {
	if (a > b) swap(a, b);

	cout << b - a << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a, b;

	while (cin >> a >> b)
		solution(a, b);
}