#include <bits/stdc++.h>
using namespace std;
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    unsigned long long int sum, n, temp;
    cin >> n;
    sum = n * (1 + n) / 2;
    for (int i = 0; i < n-1; i++){
        cin >> temp;
        sum -= temp;
    }
    cout << sum;
}