#include <bits/stdc++.h>
using namespace std;

int n, m, ticket, custom;
multiset<int> t;

class Solution{
public:
    void solve(){
        int n;
        int start, end;
        cin >> n;
        vector<pair<int, int>> seg;

        for (int i = 0; i < n; i++){
            cin >> start >> end;
            seg.push_back({start, 1});
            seg.push_back({end, -1});
        }

        sort(seg.begin(), seg.end());

        int cur_seg = 0, max_seg = 0;
        for (auto ite : seg){
            cur_seg += ite.second;
            max_seg = max(max_seg, cur_seg);
        }

        cout << max_seg << '\n';
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution Sol;
    Sol.solve();

    return 0;
}