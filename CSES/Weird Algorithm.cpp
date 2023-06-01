#include <bits/stdc++.h>
using namespace std;
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    unsigned long long int n;
 
    cin >> n;
    while (n != 1) {
        cout << n <<' ';
        if (n % 2 == 1) {
            n = n * 3 + 1;
        }
        else {
            n /= 2;
        }
    }
    cout << '1';
}