#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> w(n);

    for (int i = 0; i < n; i++) cin >> w[i];

    sort(w.begin(), w.end());

    int i = 0, j = n - 1;
    int gon = 0;
    while (i <= j) {
        if (w[i] + w[j] > k) {
            gon++;
            j--;
        }
        else {
            i++;
            j--;
            gon++;
        }
    }
    cout << gon;
    return 0;
}