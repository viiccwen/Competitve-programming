#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, total = 0;
    cin >> n;
    for (int i = 5; n / i >= 1; i *= 5)
        total += n / i;

    cout << total;
}