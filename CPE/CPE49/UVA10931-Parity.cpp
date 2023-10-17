#include <bits/stdc++.h>
using namespace std;

void solution() {
  long long num;
  while (cin >> num && num) {
    bitset<31> b(num);
    string str = b.to_string();

    int start = 0;
    while (str[start] == '0') start++;
    if (start > 0) str.erase(0, start);

    cout << "The parity of " << str << " is " << b.count() << " (mod 2).\n";
  }
}

int main() { solution(); }