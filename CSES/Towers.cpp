#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        multiset<int> ms;
        int n, k;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k;

            auto ite = ms.upper_bound(k);

            if (ite != ms.end())
                ms.erase(ite);

            ms.insert(k);
        }

        cout << ms.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution Sol;
    Sol.solve();

    return 0;
}