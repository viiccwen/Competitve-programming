#include <bits/stdc++.h>
using namespace std;
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> alt(n);
    vector<int> apm(m);
    for (int i = 0; i < n; i++) cin >> alt[i];
    for (int i = 0; i < m; i++) cin >> apm[i];
 
    sort(alt.begin(), alt.end());
    sort(apm.begin(), apm.end());
 
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (abs(alt[i] - apm[j]) <= k)
            ans++, i++, j++;
        else {
            if (alt[i] - apm[j] > k) j++;
            else i++;
        }
    }
 
    cout << ans;
    return 0;
}