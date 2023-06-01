#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
long long int cur = -1e9, max_sum = -1e9;

class Solution {
public:
    void solve() {
        cin >> n;
        long long int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            cur = max(cur + temp, temp);
            max_sum = max(cur, max_sum);
        }
        cout << max_sum;
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