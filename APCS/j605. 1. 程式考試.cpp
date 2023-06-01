#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, temp, num, max_num = -1, max_temp = 0;
    int total = 0, fault = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp >> num;
        if (num > max_num) {
            max_num = num;
            max_temp = temp;
        }
        if (num < 0) fault++;
    }
    total = max_num - n - fault * 2;
    if (total < 0) total = 0;
    cout << total << ' ' << max_temp;
}
