#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void split(ll n) {
    if (n >= 10000000) {
        split(n / 10000000);
        cout << " kuti";
        n %= 10000000;
    }
    if (n >= 100000) {
        split(n / 100000);
        cout << " lakh";
        n %= 100000;
    }
    if (n >= 1000) {
        split(n / 1000);
        cout << " hajar";
        n %= 1000;
    }
    if (n >= 100) {
        split(n / 100);
        cout << " shata";
        n %= 100;
    }
    if (n)
        cout << " " << n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll num;
    int cnt = 1;
    while (cin >> num) {
        cout << setw(4) << cnt++ << ".";
        if (num) split(num);
        else cout << " 0";

        cout << '\n';
    }

    return 0;
}
