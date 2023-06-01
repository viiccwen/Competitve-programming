#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    ull int n;
    ull int ans = 1;
    ull int num = 1e9 + 7;
    cin >> n;
    while (n > 0) {
        ans *= 2;
        ans %= num;
        n--;
    }
    cout << ans;
}