#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int n, m, ticket, custom;
    multiset<int> t;

public:
    void solve(){
        cin >> n >> m;

        for (int i = 0; i < n; i++){
            cin >> ticket;
            t.insert(ticket);
        }

        for (int i = 0; i < m; i++){
            cin >> custom;

            auto ite = t.upper_bound(custom);

            if (ite == t.begin())
                cout << "-1\n";
            else{
                cout << *(--ite) << '\n';
                t.erase(ite);
            }
        }
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