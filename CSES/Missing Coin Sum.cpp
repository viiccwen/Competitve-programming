#include <bits/stdc++.h>
using namespace std;

vector<int> v;
unsigned long long int ans = 1;

class Solution {
public:
    void solve() {
        int n;
        cin >> n;
        v.resize(n);

        for (int& i : v) cin >> i;

        sort(v.begin(), v.end());

        for (int i = 0; i < n && v[i] <= ans; i++)
            ans += v[i];

        cout << ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution Sol;
    Sol.solve();

    return 0;
}