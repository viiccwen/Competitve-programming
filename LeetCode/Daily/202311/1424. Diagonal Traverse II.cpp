class Solution {
public:
    static bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
        if (a.second.second == b.second.second) return a.second.first > b.second.first;
        return a.second.second < b.second.second;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int, pair<int, int>>> vec;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                vec.push_back({ nums[i][j], {i, i + j} });
            }
        }
        sort(vec.begin(), vec.end(), cmp);

        for (auto ite : vec) res.push_back(ite.first);

        return res;
    }
};