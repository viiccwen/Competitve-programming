#include<bits/stdc++.h>
using namespace std;

// sort the N numbers in ascending order of their modulo M value

// between an odd number and an even number (that is their modulo M value is the same) then the odd number will precede the even number

// between two odd numbers (that is their modulo M value is the same) then the larger odd number will precede the smaller odd number 

//between two even numbers (that is their modulo M value is the same) then the smaller even number will precede the larger even number.

struct List {
	int num;
	int mod;
	int evenodd; // even = 0 odd = 1 
};

bool cmp(List a, List b) {
	if (a.mod == b.mod) {
		if (a.evenodd && b.evenodd) return a.num > b.num;
		else if (!a.evenodd && !b.evenodd) return a.num < b.num;
		else if (!a.evenodd && b.evenodd) return false;
		else return true;
	}

	return a.mod < b.mod;
}

void solution(int& n, int& m) {
	cout << n << ' ' << m << '\n';

	vector<List> v(n);

	for (int i = 0, t; i < n; i++) {
		cin >> t;
		v[i] = { t, t % m, t & 1 };
	}

	sort(v.begin(), v.end(), cmp);

	for (auto i : v)
		cout << i.num << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m;

	while (cin >> n >> m && n != 0 && m != 0)
		solution(n, m);

	cout << "0 0\n";
}