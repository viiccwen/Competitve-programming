#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
unsigned long long int ans = 0;

class Solution {
public:
    void solve() {
        cin >> n;
        vector<int> v(n);

        for (int& i : v) cin >> i;

        sort(v.begin(), v.end());
        int mid = v[n / 2];

        for (const int& ite : v) {
            ans += abs(mid - ite);
        }

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