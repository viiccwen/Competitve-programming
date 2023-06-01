#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    void solve() {
        vector<int> v;
        int n;
        int count = 0;
        cin >> n;
        v.resize(n + 1);

        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            v[temp] = i;
        }

        v[0] = 1e9;
        for (int i = 1; i <= n; i++) {
            if (v[i] < v[i - 1]) count++;
        }

        cout << count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution Sol;
    Sol.solve();

    return 0;
}