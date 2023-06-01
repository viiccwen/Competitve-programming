#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, target;
map<int, int> mp;

class Solution {
public:
    string solve() {
        cin >> n >> target;

        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;

            if (mp.count(target - temp)) {
                string ans = to_string(mp[target - temp]) + ' ' + to_string(i + 1);
                return ans;
            }
            else
                mp[temp] = i + 1;
        }

        return "IMPOSSIBLE";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution Sol;
    cout << Sol.solve();

    return 0;
}