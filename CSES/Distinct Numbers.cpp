#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int ans = 1;
    for (int i = 1; i < n; i++) ans += (v[i] != v[i - 1]);
    
    cout << ans;

    return 0;
}